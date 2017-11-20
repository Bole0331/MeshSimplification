# Parallelize Mesh Simplification Algorithm with Pthread and OpenMP

- Bole Chen (bolec@andrew.cmu.edu)
- Haixin Liu (haixinl@andrew.cmu.edu)

## [Proposal](./index)

## Updated Schedule

## Works completed so far
- Designed and implemented a new mesh simplification algorithm to make it easy to parallelize.
- Discussed with professor Todd Mowry about how to parallelize this mesh simplification algorithm.
- Find potential parallel parts in the serial version algorithm, and parallized those parts with OpenMP and PThread.
- Designed the new parallel version algorithm. Trying to parallize our new mesh simplification algorithm in a multiple task queue model.

## Preliminary results
<p align="justify">&emsp;&emsp;In this section, we show our benchmark on our new serial version algorithm. We show the running time, the percentage of the potential parallel parts in the serial algorithm and how many idpedendent tasks we can generate to parallize for the algorithm for models of different size and with different simplification ratio.</p>

- Stanford Bunny: 35,292 vertices, 70,580 triangles

  | Ratio | Running time | Percentage of Parallel | Concurrent tasks number | picture                 |
  | :---: | :----------: | :--------------------: | :---------------------: | :---------------------: |
  | 0.9   | 0.812760s    | 59.2863%               | 7.417115                | ![](image/Bunny0_9.png) |
  | 0.5   | 3.792154s    | 62.8117%               | 7.233311                | ![](image/Bunny0_5.png) | 
  | 0.1   | 7.730236s    | 53.5701%               | 7.134595                | ![](image/Bunny0_1.png) |
  | 0.01  | 8.696549s    | 52.3328%               | 7.115745                | ![](image/Bunny1_1.png) |
  
- Stanford Dragon: 104,855 vertices, 209,227 triangles

- Stanford Lucy: 1,002,540 vertices, 2,005,076 triangles

## Current Issues

## First try to parallelism
<p align="justify">&emsp;&emsp; Our first try to parallelize the problem is to identify the independent loops within the serial algorithm. These loops can be distributed to many workers in a shared address space fashion. Common implementations include OpenMp and Pthread library. We implemented this parallel algorithm in both of these two ways.</p>
<p align="justify">&emsp;&emsp;The first step is to benchmark the serial algorithm and find out the time-consuming independent loops. Unfortunately, this mesh simplification algorithm is highly serial, since each modification is based on the previous one. Finally we found a loop within one modification, which updates all neighbor vertices of a merged vertex.</p>
<p align="justify">&emsp;&emsp;We firstly implemented the parallel program with Pthreads, and tested it on Macbook Pro machine. However, we observed a slow down of the running time instead of speedup. We then tested it on 8-core AWS machine, and got the similar results. We found out 3 reasons why this approach does not work:</p>
- 1. In each iteration of this loop, a shared queue is maintained. The concurrent update of this queue need to be protected by lock (or atomic operations).
- 2. The task for each worker thread is not computation intensive. It only involes a few calculations, and then updates the shared data structure.
- 3. The overhead of creating/destroying threads.
<p align="justify">&emsp;&emsp;To overcome these issues, we tried many ways to optimize it. We keep buffer to accumulate local updates, and try to use as few locks as possible. We maintain a pool of threads to avoid creating threads on the fly. However, the improvement is not satisfying. This situation is similar for OpenMP implementation.</p>

## Way to final parallelism
