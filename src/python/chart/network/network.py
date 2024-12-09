import sys
import os

current_dir = os.path.dirname(os.path.realpath(__file__))
parent_dir = os.path.dirname(os.path.dirname(current_dir))
sys.path.append(parent_dir)

from PoissonNet import Network, PoissonDistributed, NormalPackageTypeData, PackageType

import matplotlib.pyplot as plt
from matplotlib.gridspec import GridSpec

def plotFlowPerSecond(flowPerSecond: list, dataTypeFlowPerSecond: dict):
    type2Str = {1: "File", 2: "Live", 3: "Webview"}
    fig = plt.figure(figsize=(20, 10))
    plt.subplots_adjust(hspace=0.6)
    gs = GridSpec(1, 2, figure=fig, width_ratios=[3, 4])
    ax1 = fig.add_subplot(gs[0, 0])
    ax1.bar(range(0, len(flowPerSecond)), flowPerSecond)
    ax1.set_title("Total Flow Per Second")
    ax1.set_xlabel("Second")
    ax1.set_ylabel("Flow (byte)")
    
    right_grid = GridSpec(3, 1, figure=fig, left=0.55, right=0.95, wspace=0.5)
    for i, key in enumerate(dataTypeFlowPerSecond.keys()):
        ax = fig.add_subplot(right_grid[i, 0])
        ax.bar(range(0, len(dataTypeFlowPerSecond[key])), dataTypeFlowPerSecond[key])
        ax.set_title(f"{type2Str[key]} Flow Per Second")
        ax.set_xlabel("Second")
        ax.set_ylabel("Flow (byte)")
    
    plt.tight_layout()
    plt.savefig("flow_per_second.png")

def network(fileRate, liveRate, webviewRate):
    fileDistributed = PoissonDistributed(fileRate)
    liveDistributed = PoissonDistributed(liveRate)
    webviewDistributed = PoissonDistributed(webviewRate)

    filePackage = NormalPackageTypeData(1, fileDistributed, PackageType.file, 10000, 15000)
    livePackage = NormalPackageTypeData(2, liveDistributed, PackageType.live, 5000, 8000)
    webviewPackage = NormalPackageTypeData(3, webviewDistributed, PackageType.webview, 3000, 5000)
    packageTypes = [filePackage, livePackage, webviewPackage]

    network = Network(packageTypes)

    flowPerSecond = []
    dataTypeFlowPerSecond = {
        1: [],
        2: [],
        3: []
    }
    for _ in range(0, 100):
        packages = network.generatePackages()
        totalFlow = 0
        typeFlow = { 1: 0, 2: 0, 3: 0 }
        for package in packages:
            totalFlow += package.packetSize
            typeFlow[package.tag] += package.packetSize
        flowPerSecond.append(totalFlow)
        for key in typeFlow.keys():
            dataTypeFlowPerSecond[key].append(typeFlow[key])

    plotFlowPerSecond(flowPerSecond, dataTypeFlowPerSecond)

if __name__ == '__main__':
    network(2, 3, 4)