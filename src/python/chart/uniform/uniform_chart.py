import sys
import os

current_dir = os.path.dirname(os.path.realpath(__file__))
parent_dir = os.path.dirname(os.path.dirname(current_dir))
sys.path.append(parent_dir)

from PoissonNet import Network, UniformDistributed, NormalPackageTypeData, PackageType

from matplotlib import pyplot as plt

def requestGenChart():
    uniformDistributed = UniformDistributed(100, 200)
    counter = dict()
    total = 0
    for _ in range(0, 1000):
        packageCnt = uniformDistributed.genPacketCount()
        if packageCnt in counter:
            counter[packageCnt] += 1
        else:
            counter[packageCnt] = 1
        total += packageCnt

    x = list(counter.keys())
    y = [round(cnt / total * 100, 2) for cnt in counter.values()]
    plt.bar(x, y)
    plt.title("Uniform Distribution")
    plt.xlabel("Packet Count")
    plt.ylabel("Frequency (%)")
    plt.annotate(
        f"Range min: {100}, Range max: {200}", 
        (0, 0), (0, -20), 
        xycoords='axes fraction', 
        textcoords='offset points', 
        va='top'
    )
    plt.savefig("uniform_chart.png")

if __name__ == '__main__':
    requestGenChart()
