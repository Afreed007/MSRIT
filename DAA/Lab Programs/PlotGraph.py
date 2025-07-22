import matplotlib.pyplot as plt

size = [100,200,300,400]
time = [0.003,0.005,0.007,0.011]

plt.plot(size,time,marker='o')
plt.title("Matrix multiplication Time x Size")
plt.xlabel("Matrix Size (N x N)")
plt.ylabel("Time Taken (ms)")
plt.grid(True)
plt.show()
