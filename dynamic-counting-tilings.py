memo = {}

def count_tilings_recursive(uncovered):
    if len(uncovered) & 1:
        return 0
    if not uncovered:
        return 1
    if uncovered not in memo:
        i, j = min(uncovered)
        memo[uncovered] = count_tilings_recursive(uncovered - {(i, j), (i, j + 1)}) + count_tilings_recursive(uncovered - {(i, j), (i + 1, j)})
    return memo[uncovered]


def count_tilings(m, n):
    return count_tilings_recursive(frozenset((i, j) for i in range(max(m, n)) for j in range(min(m, n))))

m = int(input("Input number of rows: "))
n = int(input("Input number of columns: "))
print(count_tilings(m, n))