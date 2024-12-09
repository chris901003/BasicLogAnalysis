PoissonNet
****************************

This project aims to simulate 
network packet arrivals using Poisson processes 
with priority-based queueing, 
providing a C++ engine and 
a Python API for efficient network traffic analysis.

****************************
Basic Information
****************************

**Project**: PoissonNet

**GitHub**: https://github.com/chris901003/PoissonNet

**More Information**:
  - https://hackmd.io/@ZephyrHuang/rkrELMVEyl
  - https://www.zephyrhuang.org/poisson-net/

****************************
Problem to Solve
****************************
In modern network systems, understanding and simulating the 
behavior of packet arrivals is crucial for optimizing performance, 
managing traffic, and ensuring system reliability. 
One of the common models for simulating random events over time is 
the Poisson process, which is widely used to represent 
the arrival of packets in a network.

However, network environments are often more complex, 
involving multiple streams of data packets with 
varying priority levels and dynamic arrival rates. 
The challenge is to simulate not only the random arrival of packets 
using Poisson processes but also to model the 
priority-based processing of these packets at a service station, 
where higher priority packets are served first. Additionally, 
the system must account for fluctuating packet arrival rates 
during peak and off-peak periods.

By addressing this problem, 
we can create a simulation library that helps network engineers 
and researchers better understand packet flow dynamics, 
optimize service performance, and improve overall network efficiency.

****************************
Prospective Users
****************************

1. Network Engineers: Professionals responsible for designing 
and maintaining network infrastructures can use this library to 
simulate packet flows, analyze traffic patterns, 
and optimize network performance under various conditions.

2. Developers of Network Simulators: 
Developers creating larger-scale network simulation platforms 
can integrate this library into their tools to 
add advanced packet arrival and queueing models 
based on Poisson processes.

****************************
System Architecture
****************************

**Core Components**:

1. Implements the Poisson process to simulate random packet arrivals.
  - We will use exponential distribution random variables to model the inter-arrival times of packets.
  - In test I will ensure that the randomly generated numbers are fixed by using a fixed seed.
2. Supports multiple streams of data packets with varying arrival rates.
3. Handles priority-based packet processing with a queue system.
4. Provides high-performance computation through optimized algorithms.

**API Components**:

1. Provides a simple, user-friendly Python interface 
for users to interact with the C++ simulation engine.
2. Allows users to configure simulation parameters 
(arrival rates, priority levels, service rates) 
and retrieve simulation results.

****************************
API Description
****************************

More details about the API can be found at:
https://hackmd.io/@ZephyrHuang/rkrELMVEyl

.. code:: python

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

****************************
Engineering Infrastructure
****************************

Use Makefile and Shell scripts to buid the project.
Use GitHub Actions to verify that the build works correctly.

Schedule
========

* Week 3 (09/16): Proposal Submission
* Week 4 (09/23): Setup Development Environment and CI/CD Pipeline
* Week 5 (09/30): Implement Poisson processes
* Week 6 (10/07): Implement Priorities system
* Week 7 (10/14): Integration and Testing
* Week 8 (10/21): Develop API Components
* Week 9 (10/28): Develop API Components
* Week 10 (11/04): Build Pytyon Library
* Week 11 (11/11): Create build scripts and CI/CD pipeline
* Week 12 (11/18): Advanced Features and Dynamic Testing
* Week 13 (11/25): Improve Analysis Performance
* Week 14 (12/02): Prepare Final Report