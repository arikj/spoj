from math import factorial

input = raw_input

n,w,t,r=[int(x) for x in input().split()]

res = ((factorial(n))/(factorial(w)*factorial(t)*factorial(r)))%1000000007

print res
