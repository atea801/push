#!/usr/bin/env python3

import subprocess
import random
import time

def test_performance(size, num_tests=5):
    """Teste les performances pour une taille donnée"""
    print(f"\n=== Tests de performance pour {size} éléments ===")

    total_operations = 0
    total_time = 0

    for i in range(num_tests):
        # Génère une liste aléatoire unique
        numbers = random.sample(range(-size*2, size*2), size)

        start_time = time.time()
        try:
            cmd = ['./push_swap'] + [str(n) for n in numbers]
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
            end_time = time.time()

            if result.returncode != 0:
                print(f"  Test {i+1}: ❌ Erreur")
                continue

            operations = result.stdout.strip().split('\n') if result.stdout.strip() else []
            num_ops = len(operations)
            elapsed = end_time - start_time

            total_operations += num_ops
            total_time += elapsed

            print(f"  Test {i+1}: {num_ops} opérations en {elapsed:.3f}s")

        except subprocess.TimeoutExpired:
            print(f"  Test {i+1}: ❌ Timeout (>30s)")

    if num_tests > 0:
        avg_ops = total_operations / num_tests
        avg_time = total_time / num_tests
        print(f"  Moyenne: {avg_ops:.0f} opérations en {avg_time:.3f}s")

        # Limites théoriques approximatives
        if size <= 3:
            expected_max = 3
        elif size <= 5:
            expected_max = 12
        elif size <= 100:
            expected_max = size * 5.5  # Approximation
        else:
            expected_max = size * 11.5  # Approximation

        print(f"  Limite théorique: ~{expected_max:.0f} opérations")
        if avg_ops <= expected_max:
            print(f"  ✅ Performance acceptable")
        else:
            print(f"  ⚠️  Performance à améliorer")

def main():
    print("=== Tests de performance push_swap ===")

    # Tests de performance progressifs
    sizes = [10, 50, 100, 500]

    for size in sizes:
        test_performance(size)

    print("\n=== Test cas spéciaux de performance ===")

    # Cas déjà trié
    print("\nCas déjà trié (100 éléments):")
    numbers = list(range(100))
    start = time.time()
    result = subprocess.run(['./push_swap'] + [str(n) for n in numbers],
                          capture_output=True, text=True)
    end = time.time()
    ops = len(result.stdout.strip().split('\n')) if result.stdout.strip() else 0
    print(f"  {ops} opérations en {end-start:.3f}s")

    # Cas inversé
    print("\nCas inversé (100 éléments):")
    numbers = list(range(99, -1, -1))
    start = time.time()
    result = subprocess.run(['./push_swap'] + [str(n) for n in numbers],
                          capture_output=True, text=True)
    end = time.time()
    ops = len(result.stdout.strip().split('\n')) if result.stdout.strip() else 0
    print(f"  {ops} opérations en {end-start:.3f}s")

if __name__ == "__main__":
    main()
