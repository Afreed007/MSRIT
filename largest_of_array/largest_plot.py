import matplotlib.pyplot as plt;
sizes=[100,200,300,400,500]
times=[0.000004,0.000004,0.000005,0.000005,0.000006]
plt.title("Searching Array Time vs Array Size")
plt.plot(sizes,times,marker='o')
plt.xlabel('Array Size')
plt.ylabel('time taken in second')
plt.grid(True)
plt.show()
