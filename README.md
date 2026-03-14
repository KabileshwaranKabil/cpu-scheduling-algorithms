# CPU Scheduling
CPU scheduling deals with the problem of deciding which of the processes in the ready queue is to be allocated the CPU's Core.

There are many different CPU Schedulling algorithms
1. First-Come,First Served Scheduling
2. Shortest-Job, First Scheduling
3. Round-Robin Scheduling
4. Priority Scheduling
5. Multilevel Queue Scheduling
6. Multilevel Feedback Queue Scheduling

## First Come First Served Scheduling(FCFS)
- first process to request the CPU is allocated the CPU first
- Uses FIFO queue

when a process enters the ready queue:
- It's PCB is added to the tail of the queue.

when the CPU becomes free:
- Process at the head of the queue is selected and excuted.

FCFS performance depends on arrival order.
This causes the **Convoy Effect**
[] Many short processes wait behind one long process
[] Leads to poor CPU and I/O device Utilization

- FCFS is a [!non-preemptive scheduling](https://www.geeksforgeeks.org/operating-systems/preemptive-and-non-preemptive-scheduling/) algorithm.
- Not suitable for interactive and time sharing systems.
