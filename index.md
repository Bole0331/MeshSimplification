# Parallelize two Mesh Simplification Algorithms with Cuda and OpenMP

- Bole Chen (bolec@andrew.cmu.edu)
- Haixin Liu (haixinl@andrew.cmu.edu)

## Summary

<p align="justify">&emsp;&emsp;Surface mesh simplification is the process of reducing the number of faces used in a surface mesh while keeping the overall shape, volume and boundaries preserved as much as possible. There are lots of mesh simplification algorithms, and all of them are iterative, greedy algorithms that might cost really long time. For this project we will implement two of the mesh simplification algorithms "Quadric Error Metrics" and "Simple, Fast, and Effective Polygon Reduction Algorithm". We see some spaces for both the algorithms to speedup in parallel. So we will parallelize these two algorithms with Cuda and OpenMP to see how much speedup we can gain.</p> 

## Background

## The challenge

## Resources

- Languages: We will use C++, Cuda and OpenMP library for this Project. 
- Code Base: There is no start code for us, we will build the whole project on our own.
- Platforms: We will run our project on Mac Pro Laptop, Xeon Phi and Latedays Cluster.
- Papers:
  + [Surface Simpliﬁcation Using Quadric Error Metrics](https://people.eecs.berkeley.edu/~jrs/meshpapers/GarlandHeckbert2.pdf)
  + [A Simple, Fast, and Effective Polygon Reduction Algorithm](http://pds26.egloos.com/pds/201402/12/11/gdmag.pdf)
  + [Mesh simplification in parallel](https://pdfs.semanticscholar.org/ee52/0300bcbfcd768943d1734357d507c9e6b4d0.pdf)
  + [Real-time mesh simplification using the GPU](https://dl.acm.org/citation.cfm?id=1230128)
  + OpenMP Tutorial
  + Cuda Tutorial

## Goals and Deliverables

## Platform choice 

## Schedule
