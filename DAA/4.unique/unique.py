import matplotlib.pyplot as plt
sizes=[100,200,300,400,500]
times=[0.000053,0.000032,0.000059,0.000027,0.000029]
plt.plot(sizes,times,marker='o')
plt.title('unique list Time vs uniqueness of list')
plt.xlabel('list Size (N)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.show()


