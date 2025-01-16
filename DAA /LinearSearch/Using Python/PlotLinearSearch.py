import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("search_comparisons.csv")

plt.figure(figsize=(10, 6))
plt.plot(data["Data Size"], data["Best Case"], label="Best Case", marker='o')
plt.plot(data["Data Size"], data["Worst Case"], label="Worst Case", marker='o')
plt.plot(data["Data Size"], data["Average Case"], label="Average Case", marker='o')

plt.title("Linear Search Comparisons")
plt.xlabel("Array Size (n)")
plt.ylabel("Number of Comparisons")
plt.legend()
plt.grid(True)

plt.savefig("linear_search_plot.png")

plt.show()
