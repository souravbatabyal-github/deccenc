# deccenc - A multimedia helper

[![Build Status](https://app.travis-ci.com/sourbatabyal/deccenc.svg?branch=main)](https://app.travis-ci.com/github/souravbatabyal-github/deccenc)

## Build Guide

### Pre-requisites

1. Ubuntu 20.04 LTS
2. CMake

## Developers Guide

### Core Modules

#### Namespaces
	
All the components and modules come under deccenc namespace.

#### Classes

##### Generic Classes

1. Component: 	A singular base class; that works as a dataspace, 
		can be used as input to encoders and decoders.
		All other modules are generally inherited from the
		"component" class.
2. Logger:	A logger class, derived from Component class, capable
		of logging to a file, any pipe.

##### Media Classes

1. Media:	A sub-class of the component class. Contains data 
		about the input/output media.

##### License Classes

1. License:	Another sub-class of the component class. This class
		holds license information in a very generic sense.

##### Pipe Classes

1. Pipe:	A pipeline, that can be enabled by supplying 
		necessary information. 
		A typical Pipe takes input "Media", output 
		"Media" and "License" information.

##### Reporting, Notification and Dashboard Classes

1. Report:	A generic base class, derived by other classes, 
		to generate report on timely basis or so.
2. Notify:	A generic base class, derived by other classes, 
		to notify to another component.
		for a holistic view of the components, pipes, licenses etc.
3. Dashboard:	A generic base class, derived by other classes, 
		to prepare dashboard for a holistic view of the components, 
		pipes, licenses etc.
