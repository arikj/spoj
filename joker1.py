

t = int(raw_input());

for i in range(t):
	n = int(raw_input());
	input = raw_input;
	num = [];
	for x in input().split():
		num.append(int(x))

	num.sort();
	ans=1;
	for index,item in enumerate(num):
		ans=(ans*(item-index))%1000000007;

	print ans;

print "KILL BATMAN"

