# deviceQuery CUDA 10.0 Visual Studio 2017 C++
A C++ MFC project that uses a dialog to display output from the NVidia CUDA sample code in Utilities\deviceQuery
I like GUI since I am not a perfect typist. So, with a C++ and MFC background, I wanted the functionality of 
CUDA with a GUI. I am learning CUDA as part of my attempt to do a bit of Machine Learning and Convolutional
neural networks, inspired by the Stanford course C231n. The course focuses on visual recognition, 
using the CIFAR-10 dataset. I basically want to 'see' what is going on as any analysis is happening,

The course introduces python, via Anaconda. I know python, sort of, having used it for 7 years at work
(I am retired now...) and found it to be a problematic thing. package version problems, wierd effects with 
automatic typecasting. Anaconda is a major step forward for preventing version clashes, and I applaud the
work done. I may actually use python (via Anaconda ) for some of this. But, alas, my first and favorite is C++.

The fact that I am not a student at Stanford means that I will not have the cloud to work with, as such, 
so I have my computer with a GeForce GTX 750 video card. It just happens to have 512 CUDA cores, 
and running one of the tests in the CUDA samples showed 749 GFlops... good enough to start with.

This project is the first of several as I work up to the level of CUDA ( and C++ - I am a bit rusty...)
proficiency I would like to have. Typical of me, and programmers in general, I have not commented much 
in the code. I kept the whole thing as simple as possible when I could.

Note: on my machine I have a 'working' folder 'C:\CPP\CUDA Samples'  with the CUDA sample code projects.
This  project is in the 'C:\CPP\CUDA Samples\v10.0\1_Utilities\MFCApplication1' folder. 
You may have to do some editing for your particular location ( and where the 'CUDA Samples\v10.0\common' 
folder is for the includes ).
