# Parallelize Mesh Simplification Algorithm with Pthread and OpenMP

- Bole Chen (bolec@andrew.cmu.edu)
- Haixin Liu (haixinl@andrew.cmu.edu)

## [CheckPoint](./checkpoint)

## Summary

<p align="justify">&emsp;&emsp;Surface mesh simplification is the process of reducing the number of faces used in a surface mesh while keeping the overall shape, volume and boundaries preserved as much as possible. There are lots of mesh simplification algorithms, and all of them are iterative, greedy algorithms that might cost really long time. For this project we will implement two of the mesh simplification algorithms "Quadric Error Metrics" and "Simple, Fast, and Effective Polygon Reduction Algorithm". We see some potential spaces for both the algorithms to speedup in parallel. So we will parallelize these two algorithms with Cuda and OpenMP to see how much speedup we can gain.</p> 

## Background

<p align="justify">&emsp;&emsp;Computer graphics processing typically requires many different levels of model detail. In general, the higher the level of detail is, the more computational cost is needed. Depends on various applications, the necessary level of detail may vary significantly. The mesh simplification algorithm can be used to produce high quality model approximations and reduce processing time.</p>

<p align="justify">&emsp;&emsp;One surface simplification algorithm that we are specially interested in is using quadric error metrics. This algorithm focuses on polygonal models, which only consists of triangles. The main idea of this algorithm is based on iterative contraction of vertex pairs, which is a generalizaiton of edge contraction. The main advantages of this algorithm are improved efficiency, quality and generality. Our work will be using this as serial version algorithm, and expoiting intrinsic parallelism of graphic processing.</p>

## The challenge

<p align="justify">&emsp;&emsp;Although the parallelism is intrinsic for graphics processing, serveral challenges also present in efficient implementation.
- Workload: This algorithm is iterative, and each iteration of execution is dependent on the last one. For CUDA and OpenMP, communication may not be a major problem, but synchronization with locks may be a source of inefficiency.
- Constraints: Since the algorithm operates on vertices and edges of mesh, simply distribute work based on pixels may not work. It is also hard to deal with shared vertices and edges across partitions. The layout of data need to be well organized to make use of locality.</p>

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

<p align="justify">&emsp;&emsp;Our minimum goal for this project is to implement the parallel version mesh simplification algorithm with Cuda and OpenMP. Right now for a object that consists with millions of patches, it takes really a long time to run the serial version mesh simplification algorithm, which is intolerable. Hence for our parallel version implementationm, we want to show in the poster session that it can finish in seconds.</p>

<p align="justify">&emsp;&emsp;We will implement two different mesh simplification algorithms and parallelize them with Cuda and OpenMP. So we will compare the performance of differnt combinations. The problems itself is a graphic problem, so we believe Cuda could be a ideal fit for this mesh simplification problem. We will do a lot of experiments and analyses work to compare these two parallel model to understand deeply why one performs better than the other one. </p>

## Platform choice 

- For computer graphics processing, GPU is an ideal platform since it is initially designed to accelerate the creation of images.
- Graphic processing based on mesh models have been working well with GPUs.
- OpenMP is a shared address space framework which utilizes parallelism of single node, and is suitable for single output device on the same node.

## Schedule

- Week 1 (by 11/5):  Read related works, understand two algorithms.
- Week 2 (by 11/12): Implement two mesh simplification algorithms in serial version.
- Week 3 (by 11/19): Optimize serial version code and parallelize these two algorithms with Cuda.
- Week 4 (by 11/26): Parallelize algorithms with Cuda and OpenMP.
- Week 5 (by 12/3):  Parallelize algorithms with OpenMP and do experiments.
- Week 6 (by 12/10): Do experiments and work on final report.
