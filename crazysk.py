t = int(raw_input());

for i in range(t):
	inp = raw_input();
	n,k = inp.split();
	n = long(n);
	k = long(k); 
	if n%(k-1) == 0:
		ans = n/(k-1) - 1;
	else:
		ans = n/(k-1);

	ans = ans + n;
	print ans;


