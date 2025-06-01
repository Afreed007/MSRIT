import matplotlib.pyplot as plt;
sizes=[2,15,20,25,30]
times=[0.000004,0.000055,0.000094,0.000269,0.000349]
plt.title("Matrix Multiplication Time vs Matrix Size")
plt.plot(sizes,times,marker='o')
plt.xlabel('Matrix Size (N*N)')
plt.ylabel('time taken in second')
plt.grid(True)
plt.show()
