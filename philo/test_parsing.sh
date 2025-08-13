#!/bin/bash
# test_parsing.sh

echo "=== VALID CASES (Should succeed) ==="
./philo 5 800 200 200 && echo "✓ Basic case"
./philo 4 410 200 200 7 && echo "✓ With must_eat"
./philo 05 0800 0200 0200 && echo "✓ Leading zeros"
./philo "  5" " +800" "+200" "  +200" && echo "✓ Whitespace and plus"

echo -e "\n=== INVALID CASES (Should fail) ==="
./philo && echo "✗ Should fail: No args" || echo "✓ Correctly failed: No args"
./philo 0 800 200 200 && echo "✗ Should fail: Zero philosophers" || echo "✓ Correctly failed: Zero"
./philo -5 800 200 200 && echo "✗ Should fail: Negative" || echo "✓ Correctly failed: Negative"
./philo 5a 800 200 200 && echo "✗ Should fail: Non-numeric" || echo "✓ Correctly failed: Non-numeric"
./philo 2147483648 800 200 200 && echo "✗ Should fail: Too large" || echo "✓ Correctly failed: Too large"
./philo "" 800 200 200 && echo "✗ Should fail: Empty string" || echo "✓ Correctly failed: Empty"
