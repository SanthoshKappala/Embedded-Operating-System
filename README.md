# Embedded Operating System in C

This repository demonstrates the implementation of fundamental components of an embedded operating system in C. It serves as a practical guide for understanding low-level OS concepts and their application in embedded systems.

## Repository Structure

The repository is organized into individual C files, each implementing a specific component or concept:

* `Thread.c` – Basic thread management
* `Mutex.c` – Mutexes for mutual exclusion
* `Semaphore.c` – Semaphores for synchronization
* `MessageQueue.c` – Message queues for inter-process communication
* `SharedMemory.c` – Shared memory for data exchange
* `Socket.c` – Socket programming for network communication
* `Pipe.c` – Pipes for inter-process communication
* `Exec.c` – Process execution
* `Fork.c` – Process forking
* `PID.c` – Process ID management
* `RDWRLock.c` – Read-write locks
* `Barrier.c` – Barriers for thread synchronization
* `CondVar.c` – Condition variables
* `FIFO.c` – First-In-First-Out scheduling
* `Orphan.c` – Orphan process handling
* `SharedMemStruct.c` – Shared memory structures
* `Makefile` – Build automation script

## Features

* Clear and concise implementations of each OS component
* Well-commented code for easy understanding
* Designed for educational purposes and hands-on learning

## Usage Instructions

1. **Clone the repository**:

```bash
git clone https://github.com/SanthoshKappala/Embedded-Operating-System.git
cd Embedded-Operating-System
```

2. **Compile a specific C file**:

```bash
gcc filename.c -o outputname
```

Replace `filename.c` with the desired C file and `outputname` with your preferred output file name.

3. **Run the compiled program**:

```bash
./outputname
```

## Example

To compile and run the thread management implementation:

```bash
gcc Thread.c -o thread
./thread
```

Follow the on-screen prompts to interact with the thread operations.

## Contributing

Contributions are welcome. Feel free to fork the repository, make improvements, and submit pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

