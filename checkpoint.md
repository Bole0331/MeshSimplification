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
  | 0.5   | 3.792154s    | 62.8117%               | 7.233311                |                         | 
  | 0.1   | 7.730236s    | 53.5701%               | 7.134595                |                         |
  | 0.01  | 8.696549s    | 52.3328%               | 7.115745                |                         |
  
- Stanford Dragon: 104,855 vertices, 209,227 triangles

- Stanford Lucy: 1,002,540 vertices, 2,005,076 triangles

## Current Issues

## First try to parallelism

## Way to final parallelism
