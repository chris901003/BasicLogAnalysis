import sys
import os

current_dir = os.path.dirname(os.path.realpath(__file__))
parent_dir = os.path.dirname(os.path.dirname(os.path.dirname(current_dir)))
sys.path.append(parent_dir)

from PoissonNet import FilePackageInfoData, LivePackageInfoData, WebViewPackageInfoData
from PoissonNet import LiveQuality

import matplotlib.pyplot as plt

def savePlot(
        size_per_second: list, 
        title: str, 
        xlabel: str, 
        filename: str, 
        packetSize: int, 
        save: bool = True, 
        clear: bool = True
    ):
    plt.bar(range(0, len(size_per_second)), size_per_second)
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel("Size (byte)")
    plt.annotate(
        f"Packet Size: {packetSize}",
        (0, 0), (0, -20),
        xycoords='axes fraction',
        textcoords='offset points',
        va='top'
    )
    if save:
        plt.savefig(filename)
    if clear:
        plt.cla()

def fileRequest(packetSize):
    filePackageType = FilePackageInfoData(1, packetSize)
    size_per_second = []
    while True:
        packetData = filePackageType.generatePackage()
        if packetData.packetSize == 0:
            break
        size_per_second.append(packetData.packetSize)

    savePlot(size_per_second, "File Request", "Second", "file_request.png", packetSize)
    return size_per_second

def liveRequest(packetSize):
    livePackageType = LivePackageInfoData(1, packetSize, LiveQuality.medium)
    size_per_second = []
    while True:
        packetData = livePackageType.generatePackage()
        if packetData.packetSize == 0:
            break
        size_per_second.append(packetData.packetSize)
    
    savePlot(size_per_second, "Live Request", "Second", "live_request.png", packetSize)
    return size_per_second

def webviewRequest(packetSize):
    webviewPackageType = WebViewPackageInfoData(1, packetSize)
    size_per_second = []
    while True:
        packetData = webviewPackageType.generatePackage()
        if packetData.packetSize == 0:
            break
        size_per_second.append(packetData.packetSize)
    
    savePlot(size_per_second, "Webview Request", "Second", "webview_request.png", packetSize)
    return size_per_second

if __name__ == '__main__':
    file = fileRequest(25000)
    live = liveRequest(25000)
    webview = webviewRequest(25000)
    savePlot(file, "File Request", "Second", "file_request.png", 25000, False, False)
    savePlot(live, "Live Request", "Second", "live_request.png", 25000, False, False)
    savePlot(webview, "Mixed Request", "Second", "mixed.png", 25000, True, True)
