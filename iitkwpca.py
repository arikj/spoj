from collections import Counter

t = int(raw_input())

for i in range(t):
	inp = raw_input()
	words = inp.split()
	count = len(Counter(words))
	print count
