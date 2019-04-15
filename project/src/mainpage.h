#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*
 *
 * Copyright 2019 John Strobel
 *
 *
 *
 *
 */

/*! \mainpage Braitenberg Vehicle Simulation
 *
 * \section Introduction Introduction
 *
 *
 *The Braitenberg Vehicle simulator is a project in development for the
 *University of Minnesota Program Design and Development class. The purpose of
 *this simulation is to digitally represent Braitenberg Vehicles (BVs) and their
 *environment. BVs are extremely simple robots from which complex behaviors can
 *arise; the four behaviors are summarized in the following image. This project
 *is comprised of three main parts: the Arena class, the BraitenbergVehicle
 *class, and the GraphicsArenaViewer class.
 *
 *
 * \section Classes Classes
 *
 *
 *The Arena is responsible for the actual simulation, and does all the work
 *pertaining to entity instantiation, time tracking, collision handling, etc.
 *It contains a list of all ArenaEntities, which represents all entities present
 *in the system. Modification of this class should be done in Arena.h and
 *Arena.cc. The critical method to watch out for is UpdateEntitiesTimestep,
 *which handles all the actual work for updating entities.
 *
 *The BraitenbergVehicle is the class that describes the behaviors of the BVs.
 *It inherits from ArenaMobileEntity (which, in turn, inherits from ArenaEntity)
 *and contains a Behavior class that allows for further modularity when it comes
 *to the four behaviors. This behavior class is an example of the strategy
 *pattern. The reason this class is so critical to the project is that the
 *logic for the various aspects of the vehicles is much more intricate than
 *other, simpler, entities.
 *
 *BVs have many properties. Each behavior, which can be affected by lights,
 *food, or other BVs, has some control over both wheels, and is calculated by
 *using the sensors on the front of the BV. The BVs can also change color
 *depending on which entities they are currently sensing, and based on their
 *level of hunger. Finally, BVs can die through starvation or being consumed by
 *a predator (a subclass of BV that can consume other BVs.)
 *
 *The GraphicsArenaViewer class draws the entire simulation, taking information
 *from both the Arena and the BVs in order to do so. It uses the nanoGUI library
 *and the observer pattern to do so. Any surface-level modifications to the GUI
 *should be done through params.h, which controls many of the default values of
 *the simulation, or through the creation of a different JSON file (see
 *project/scenes for example setups).
 *
 *
 * \section Simulation Simulation
 *
 *
 *More broadly, the simulation is controlled through a third class called the
 *controller. The controller class has an instance of both an Arena object and a
 *GraphicsArenaViewer. It essentially runs both of these classes, sending the
 *command to update the current simulation time to each. In main, this is the
 *class that is instantiated and run; every entity is created as a result of the
 *controller’s code.
 *
 */

#endif  // SRC_MAINPAGE_H_
