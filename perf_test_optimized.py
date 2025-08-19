#!/usr/bin/env python3

import subprocess
import time
import random

def execute_push_swap(numbers):
    """Exécute push_swap avec une liste de nombres et retourne les instructions"""
    try:
        cmd = ['./push_swap'] + [str(n) for n in numbers]
        start_time = time.time()
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
        end_time = time.time()
        if result.returncode != 0:
            return None, f"Error: {result.stderr.strip()}", 0
        operations = result.stdout.strip().split('\n') if result.stdout.strip() else []
        return operations, None, end_time - start_time
    except subprocess.TimeoutExpired:
        return None, "Timeout", 0
    except Exception as e:
        return None, str(e), 0

def test_performance_optimized():
    print("=== TESTS DE PERFORMANCE ALGORITHME OPTIMISÉ ===\n")

    test_sizes = [10, 50, 100, 500]

    for size in test_sizes:
        print(f"=== Tests de performance pour {size} éléments ===")

        total_ops = 0
        total_time = 0
        tests = 5

        for i in range(tests):
            # Génération de nombres aléatoires
            numbers = random.sample(range(1, size * 10), size)

            operations, error, exec_time = execute_push_swap(numbers)
            if error:
                print(f"  Test {i+1}: Erreur - {error}")
                continue

            op_count = len(operations)
            total_ops += op_count
            total_time += exec_time

            print(f"  Test {i+1}: {op_count} opérations en {exec_time:.3f}s")

        avg_ops = total_ops / tests
        avg_time = total_time / tests

        print(f"  Moyenne: {avg_ops:.0f} opérations en {avg_time:.3f}s")

        # Limites théoriques pour évaluation
        if size == 10:
            limit = 55
        elif size == 50:
            limit = 275
        elif size == 100:
            limit = 550
        elif size == 500:
            limit = 5750

        print(f"  Limite théorique: ~{limit} opérations")

        if avg_ops <= limit:
            print(f"  ✅ Performance excellente")
        elif avg_ops <= limit * 1.5:
            print(f"  ✅ Performance acceptable")
        else:
            print(f"  ⚠️  Performance à améliorer")

        print()

    # Test cas spéciaux
    print("=== Test cas spéciaux de performance ===\n")

    # Cas déjà trié
    print("Cas déjà trié (100 éléments):")
    sorted_numbers = list(range(1, 101))
    operations, error, exec_time = execute_push_swap(sorted_numbers)
    if operations is not None:
        print(f"  {len(operations)} opérations en {exec_time:.3f}s")

    # Cas inversé
    print("\nCas inversé (100 éléments):")
    reversed_numbers = list(range(100, 0, -1))
    operations, error, exec_time = execute_push_swap(reversed_numbers)
    if operations is not None:
        print(f"  {len(operations)} opérations en {exec_time:.3f}s")

if __name__ == "__main__":
    test_performance_optimized()
