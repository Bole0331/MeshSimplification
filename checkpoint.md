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
<p align="justify">&emsp;&emsp;In this section, we show our benchmark on our new serial version algorithm. We show the running time, the percentage of the potential parallel parts in the serial algorithm and how many idpedendent tasks we can generate to parallize for the algorithm for models of different size and with different simplification ratio.

## Current Issues

## First try to parallelism

## Way to final parallelism
