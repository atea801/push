#!/usr/bin/env python3

import sys
import subprocess
import random

def execute_push_swap(numbers):
    """Exécute push_swap avec une liste de nombres et retourne les instructions"""
    try:
        cmd = ['./push_swap'] + [str(n) for n in numbers]
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
        if result.returncode != 0:
            return None, f"Error: {result.stderr.strip()}"
        return result.stdout.strip().split('\n') if result.stdout.strip() else [], None
    except subprocess.TimeoutExpired:
        return None, "Timeout"
    except Exception as e:
        return None, str(e)

def apply_operations(a, b, operations):
    """Applique les opérations sur les piles A et B"""
    for op in operations:
        if not op:
            continue

        if op == 'sa':
            if len(a) >= 2:
                a[0], a[1] = a[1], a[0]
        elif op == 'sb':
            if len(b) >= 2:
                b[0], b[1] = b[1], b[0]
        elif op == 'ss':
            if len(a) >= 2:
                a[0], a[1] = a[1], a[0]
            if len(b) >= 2:
                b[0], b[1] = b[1], b[0]
        elif op == 'pa':
            if b:
                a.insert(0, b.pop(0))
        elif op == 'pb':
            if a:
                b.insert(0, a.pop(0))
        elif op == 'ra':
            if a:
                a.append(a.pop(0))
        elif op == 'rb':
            if b:
                b.append(b.pop(0))
        elif op == 'rr':
            if a:
                a.append(a.pop(0))
            if b:
                b.append(b.pop(0))
        elif op == 'rra':
            if a:
                a.insert(0, a.pop())
        elif op == 'rrb':
            if b:
                b.insert(0, b.pop())
        elif op == 'rrr':
            if a:
                a.insert(0, a.pop())
            if b:
                b.insert(0, b.pop())

def is_sorted(lst):
    """Vérifie si une liste est triée en ordre croissant"""
    return all(lst[i] <= lst[i+1] for i in range(len(lst)-1))

def test_push_swap(numbers):
    """Teste push_swap avec une liste de nombres"""
    print(f"Test avec: {numbers}")

    operations, error = execute_push_swap(numbers)
    if error:
        print(f"  ❌ Erreur: {error}")
        return False

    # Simulation des opérations
    a = numbers.copy()
    b = []

    apply_operations(a, b, operations)

    # Vérifications
    success = True

    if b:
        print(f"  ❌ La pile B n'est pas vide: {b}")
        success = False

    if not is_sorted(a):
        print(f"  ❌ La pile A n'est pas triée: {a}")
        success = False

    if set(a) != set(numbers):
        print(f"  ❌ Les éléments ont changé: {a} vs {numbers}")
        success = False

    if success:
        print(f"  ✅ Tri réussi en {len(operations)} opérations")

    return success

def main():
    print("=== Tests du programme push_swap ===\n")

    # Tests de base
    test_cases = [
        [1],  # Un seul élément
        [1, 2],  # Déjà trié
        [2, 1],  # Inverse simple
        [1, 2, 3],  # Déjà trié
        [3, 2, 1],  # Totalement inverse
        [2, 1, 3],  # Mélangé
        [1, 3, 2],  # Mélangé
        [3, 1, 2],  # Mélangé
        [1, 2, 3, 4, 5],  # Déjà trié 5 éléments
        [5, 4, 3, 2, 1],  # Inverse 5 éléments
        [3, 1, 4, 2, 5],  # Mélangé 5 éléments
        [-1, -2, -3],  # Négatifs
        [-3, 1, -1, 2],  # Mélange positifs/négatifs
        [42, 17, 89, 3, -15, 100],  # 6 éléments
    ]

    success_count = 0
    for test_case in test_cases:
        if test_push_swap(test_case):
            success_count += 1
        print()

    print(f"Résultats: {success_count}/{len(test_cases)} tests réussis")

    # Tests aléatoires
    print("\n=== Tests aléatoires ===")
    random_success = 0
    random_tests = 10

    for i in range(random_tests):
        size = random.randint(10, 50)
        numbers = random.sample(range(-100, 100), size)
        print(f"\nTest aléatoire {i+1} ({size} éléments)")
        if test_push_swap(numbers):
            random_success += 1

    print(f"\nTests aléatoires: {random_success}/{random_tests} réussis")

if __name__ == "__main__":
    main()
