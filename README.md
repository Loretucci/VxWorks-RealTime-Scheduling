# VxWorks Real-Time Application

## Project Overview
This repository contains the source code and documentation for a **Real-Time Systems** project developed on the **VxWorks** operating system. 

The goal of the project was to design and implement a real-time application composed of periodic tasks sharing resources, governed by specific access protocols (PIP and HLP) to prevent priority inversion and deadlocks. The system behavior was validated using **SystemViewer**.

## System Specification

### Task Set
The application consists of 3 periodic tasks with distinct periods, designed to create a high-load scenario (U<sub>tot</sub> ≈ 0.83) with complex resource contention.

| Task | Period (T<sub>i</sub>) | Execution Time (C<sub>i</sub>) | Resources Used |
| :---: | :---: | :---: | :---: |
| **&tau;<sub>1</sub>** | 10 ms | 2 ms | R<sub>1</sub> |
| **&tau;<sub>2</sub>** | 15 ms | 4 ms | R<sub>3</sub>, R<sub>2</sub> |
| **&tau;<sub>3</sub>** | 30 ms | 8 ms | R<sub>1</sub>, R<sub>2</sub> |

### Resource Access Protocols
To manage shared resources and ensure schedulability, the following protocols were analyzed and implemented:
* **Priority Inheritance Protocol (PIP)**
* **Highest Locker Protocol (HLP)**

## Feasibility Analysis
A theoretical analysis was performed before implementation to guarantee the system's schedulability:
1.  **Utilization Analysis:** Total utilization is U<sub>p</sub> = 0.83, satisfying the necessary condition (U ≤ 1).
2.  **Response Time Analysis (RTA):** Calculated considering the **Blocking Time (B<sub>i</sub>)** introduced by lower-priority tasks holding shared resources.
3.  **Deadlock Detection:** The report highlights a potential deadlock scenario under specific conditions (Circular Wait) and discusses how HLP resolves or mitigates these issues compared to standard mutexes.

## Technologies & Tools
* **OS:** Wind River VxWorks (tested on `vxsim0`)
* **Language:** C 
* **Analysis Tools:** SystemViewer (Wind River Workbench)
* **Concepts:** Preemptive Scheduling, Semaphores, Mutexes, Deadlock Prevention.

## Project Structure
* `src/`: Contains the C source files (`.c`, `.h`) for the tasks and system configuration.
* `report/`: Includes the detailed PDF report with feasibility calculations and SystemViewer screenshots.
* `includes/`: Header files defining task parameters and resource identifiers.

## Key Observations
* **PIP vs HLP:** The project analyzes the trade-offs between Priority Inheritance and Highest Locker Protocol. 
* **Deadlock Scenario:** A specific case study (documented in the report) demonstrates how circular dependencies can lead to deadlock and how the correct protocol application prevents system freeze.

---
### Authors
* **Lorenzo Tucci**
* Leonardo Carnevali
* Jacopo Ferri

*Course: Real Time Systems and Programming for Automation*
