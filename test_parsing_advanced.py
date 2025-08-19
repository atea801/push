#!/usr/bin/env python3

import subprocess
import sys

def run_push_swap(args_list):
    """Exécute push_swap avec une liste d'arguments et retourne le code de retour"""
    try:
        cmd = ['./push_swap'] + args_list
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=5)
        return result.returncode, result.stdout.strip(), result.stderr.strip()
    except subprocess.TimeoutExpired:
        return -1, "", "Timeout"

def test_parsing_cases():
    """Tests spécifiques au parsing amélioré"""
    print("=== TESTS PARSING AMÉLIORÉ ===\n")

    test_cases = [
        # Format: (description, args, expected_returncode)
        ("Arguments séparés classiques", ["1", "2", "3", "4"], 0),
        ("Arguments avec espaces", ["1 2", "3 4"], 0),
        ("Mélange des deux formats", ["1", "2 3", "4"], 0),
        ("Espaces multiples", ["  1   2  ", "  3   4  "], 0),
        ("Arguments vides ignorés", ["", "1 2"], 0),
        ("Arguments d'espaces ignorés", ["   ", "1 2"], 0),
        ("Déjà trié avec nouveau format", ["1 2 3", "4 5 6"], 0),
        ("Doublons dans même argument", ["1 1", "2 3"], 1),
        ("Doublons entre arguments", ["1 2", "2 3"], 1),
        ("Nombre invalide dans argument", ["1 abc", "2 3"], 1),
        ("Overflow dans argument", ["1 2147483648", "2"], 1),
        ("Arguments mixtes valides", ["42", "-15 0", "100"], 0),
    ]

    success_count = 0
    for description, args, expected_code in test_cases:
        print(f"Test: {description}")
        print(f"  Commande: ./push_swap {' '.join(repr(arg) for arg in args)}")

        returncode, stdout, stderr = run_push_swap(args)

        if returncode == expected_code:
            print(f"  ✅ Résultat attendu (code {returncode})")
            success_count += 1
        else:
            print(f"  ❌ Attendu: code {expected_code}, obtenu: code {returncode}")
            if stderr:
                print(f"     Erreur: {stderr}")
        print()

    print(f"Résultats parsing: {success_count}/{len(test_cases)} tests réussis\n")

def test_complex_sorting():
    """Tests de tri plus complexes avec le nouveau parsing"""
    print("=== TESTS TRI COMPLEXES ===\n")

    complex_cases = [
        ["10 20", "5 15"],  # Mélange simple
        ["100 50", "25 75", "12 37"],  # 6 éléments répartis
        ["-5 -10", "0", "5 10"],  # Avec négatifs
        ["1000", "500 750", "250 125", "375"],  # 6 éléments variés
    ]

    for i, args in enumerate(complex_cases, 1):
        print(f"Test complexe {i}: {' '.join(repr(arg) for arg in args)}")

        returncode, stdout, stderr = run_push_swap(args)

        if returncode == 0:
            if stdout:
                op_count = len(stdout.split('\n'))
                print(f"  ✅ Tri réussi en {op_count} opérations")
            else:
                print(f"  ✅ Déjà trié (0 opérations)")
        else:
            print(f"  ❌ Erreur (code {returncode})")
            if stderr:
                print(f"     {stderr}")
        print()

def main():
    print("TESTS COMPLETS DU PARSING AMÉLIORÉ\n")
    print("=" * 50)

    test_parsing_cases()
    test_complex_sorting()

    print("Tests terminés!")

if __name__ == "__main__":
    main()
