from PoissonNet import Network, PoissonDistributed, NormalPackageTypeData, PackageType

if __name__ == '__main__':
    poissonDistributed = PoissonDistributed(2)
    packageType = NormalPackageTypeData(1, poissonDistributed, PackageType.file, 2000, 2500)
    packageTypes = [packageType]
    network = Network(packageTypes)
    for i in range(0, 3):
        packages = network.generatePackages()
        print("===== Result =====")
        for package in packages:
            print(f"Id: {package.id}, Tag: {package.tag}, Size: {package.packetSize}, Count: {package.packetCount}")
        print("==================")
    print("===== End =====")
