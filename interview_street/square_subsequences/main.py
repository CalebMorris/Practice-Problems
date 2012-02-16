def powerset(seq):
	if len(seq) <= 1:
		yield seq
		yield []
	else:
		for x in powerset(seq[1:]):
			yield [seq[0]]+x
			yield x

def is_square(s):
    if s == "":
        return False
    else:
        return s[:len(s)/2] == s[len(s)/2:]

num = raw_input()
for x in range(int(num)):
    tmp = raw_input()
    sets = powerset(list(tmp))
    sum = 0
    for y in sets:
        sum += is_square("".join(y))
    print sum
