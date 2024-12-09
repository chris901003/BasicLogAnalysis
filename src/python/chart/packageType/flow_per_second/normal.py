import sys
import os

current_dir = os.path.dirname(os.path.realpath(__file__))
parent_dir = os.path.dirname(os.path.dirname(os.path.dirname(current_dir)))
sys.path.append(parent_dir)

from PoissonNet import Network, PoissonDistributed, NormalPackageTypeData, PackageType

import matplotlib.pyplot as plt

def fileFlowPerSecond(poissonRate):
    poissonDistributed = PoissonDistributed(poissonRate)
    packageType = NormalPackageTypeData(1, poissonDistributed, PackageType.file, 2000, 2500)
    packageTypes = [packageType]
    network = Network(packageTypes)
    
    flowPerSecond = []

    for _ in range(0, 100):
        packages = network.generatePackages()
        totalFlow = 0
        for package in packages:
            totalFlow += package.packetSize
        flowPerSecond.append(totalFlow)
    
    plt.bar(range(0, len(flowPerSecond)), flowPerSecond)
    plt.title("File Flow Per Second (Poisson Distribution)")
    plt.xlabel("Second")
    plt.ylabel("Flow (byte)")
    plt.annotate(
        f"Rate: {poissonRate}", 
        (0, 0), (0, -20), 
        xycoords='axes fraction', 
        textcoords='offset points', 
        va='top'
    )
    plt.savefig("file.png")

def liveFlowPerSecond(poissonRate):
    poissonDistributed = PoissonDistributed(poissonRate)
    packageType = NormalPackageTypeData(1, poissonDistributed, PackageType.live, 2000, 2500)
    packageTypes = [packageType]
    network = Network(packageTypes)
    
    flowPerSecond = []

    for _ in range(0, 100):
        packages = network.generatePackages()
        totalFlow = 0
        for package in packages:
            totalFlow += package.packetSize
        flowPerSecond.append(totalFlow)
    
    plt.bar(range(0, len(flowPerSecond)), flowPerSecond)
    plt.title("Live Flow Per Second (Poisson Distribution)")
    plt.xlabel("Second")
    plt.ylabel("Flow (byte)")
    plt.annotate(
        f"Rate: {poissonRate}", 
        (0, 0), (0, -20), 
        xycoords='axes fraction', 
        textcoords='offset points', 
        va='top'
    )
    plt.savefig("live.png")

def webviewFlowPerSecond(poissonRate):
    poissonDistributed = PoissonDistributed(poissonRate)
    packageType = NormalPackageTypeData(1, poissonDistributed, PackageType.webview, 2000, 2500)
    packageTypes = [packageType]
    network = Network(packageTypes)
    
    flowPerSecond = []

    for _ in range(0, 100):
        packages = network.generatePackages()
        totalFlow = 0
        for package in packages:
            totalFlow += package.packetSize
        flowPerSecond.append(totalFlow)
    
    plt.bar(range(0, len(flowPerSecond)), flowPerSecond)
    plt.title("Webview Per Second (Poisson Distribution)")
    plt.xlabel("Second")
    plt.ylabel("Flow (byte)")
    plt.annotate(
        f"Rate: {poissonRate}", 
        (0, 0), (0, -20), 
        xycoords='axes fraction', 
        textcoords='offset points', 
        va='top'
    )
    plt.savefig("webview.png")

if __name__ == '__main__':
    fileFlowPerSecond(5)
    plt.cla()
    liveFlowPerSecond(5)
    plt.cla()
    webviewFlowPerSecond(5)
