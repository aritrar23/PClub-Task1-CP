# Editorial of the problem Voldemort's Castle
We can break the problem into 3 parts -

i) Deducing the colour of each curse (the curses are A,B,...F)

ii) Find the 6 consecutive primes whose sum is given

iii) Matching each prime to a curse, following the rule that potency of red curse < green curse < blue curse

### Solution of (i) Deducing the colour of each curse

To deduce the colour of each curse, we need to solve the colour equations given for the pairs of curses. Each test case provides six pairs of curses with the resulting combined colours. Our goal is to determine which colour (Red, Green, or Blue) each curse corresponds to. First we understand the colour combinations that Red + Green = Brown, Red + Blue = Purple, Green + Blue = Teal, Red + Red = Red, Green + Green = Green and Blue + Blue = Blue. Now we use a backtracking algorithm to try different combinations of colours for each curse. We check if the assigned colours for the pairs match the given result colours. If a combination satisfies all given pairs, we have found a valid solution.


Implementation - We reate a recursive function to try all possible combinations of colours for the curses. We then use an unordered map to store the assigned colours for each curse and verify against the given pairs.

### Solution of (ii) Finding the 6 consecutive primes whose sum is given
Given the sum of the potencies of 6 curses, which are consecutive prime numbers, we need to find these 6 primes. We use the Sieve of Eratosthenes technique to solve this problem efficiently. First we generate a list of prime numbers up to a reasonable limit (e.g., 1,000,000) using the Sieve of Eratosthenes. Then to find the 6 consecutive primes, we use a clever algorithm. We first find the average of the 6 primes by dividing the sum by 6, then find the nearest prime to the average, then compute the average of these 2 primes to see if it is greater or lesser than the actual average of the 6 primes, based on which we find the nearet greater or nearest lower prime, and so on. We finally end up with 6 consecutive primes whose sum equals the given number.

### Solution of (iii) Matching each prime to a curse
After determining the colours of the curses and the 6 consecutive primes, we need to match each prime to a curse based on the given rules : Red curse < Green curse < Blue curse in potency. For curses of the same colour, the lexicographically greater curse has more potency. First we sort the curses by their colours (Red, Green, Blue). Within each colour group, we sort curses lexicographically. Then we assign the primes to the curses, assigning  the smallest prime to the first curse in the sorted order, and so on.
