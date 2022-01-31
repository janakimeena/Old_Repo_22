
def maxSubArraySum(a,size):
	
	global_max = a[0]
	positive_sum_till_here = 0
	
	for i in range(0, size):
		positive_sum_till_here = positive_sum_till_here + a[i]
		if (positive_sum_till_here > global_max ):
			global_max = positive_sum_till_here
		if positive_sum_till_here < 0:
			positive_sum_till_here = 0
		
		# Do not compare for all elements. Compare only
		# when max_ending_here > 0
		
	return global_max

a = [-13, -3, -25, -20, -3, -16, -23, -12, -5, 22, -1, -4, -7, 100]

max_val = maxSubArraySum([-2,-3,4,-1,-2,1,5,-3],8)
print(max_val)
