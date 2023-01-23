import scipy
from scipy.stats import *
# define dataset
# data = [3, 4, 4, 5, 7, 8, 12, 14, 14, 15, 17, 19, 22, 24, 24, 24, 25, 28, 28, 29]
# data = [48,66,74,86,78]
data = [52, 58, 82, 35, 84]
# calculate standard error of the mean
a = scipy.mean(data)
b = sem(data)
print(a)
print(b)
