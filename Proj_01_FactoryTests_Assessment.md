### Assessment for Project Iteration 01 - FactoryTests (Graded By: Hrushikesh)

#### Total score: _19_ / _20_

Run on March 28, 18:01:55 PM.


#### Release Branch

+ Pass: Checkout release branch.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Factory

+ Pass: Graded on Canvas.




#### Tests

+ Pass: Graded on Canvas.




#### Compile Tests

+ Pass: Clean project.



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/arenaviewer" exists.

+ Pass: Change into directory "tests-i".

+ Pass: Check that make compiles.



+ Pass: Change into directory "..".

+ Pass: Check that file "./build/bin/tests-i" exists.


#### Collision Avoidance Tests

+  _2_ / _2_ : Pass: Upon collision with a wall, the robot went into avoidance?



+  _2_ / _2_ : Pass: Upon collision with another robot, the robot went into avoidance?



+  _2_ / _2_ : Pass: Upon collision while in avoidance, it went into avoidance in the other direction?



+  _2_ / _2_ : Pass: The robot moves for 20 units after collision?



+  _1_ / _2_ : Fail: After reversing the robot turned 45 degrees?
<pre>
<b>Comments: 
</b>The robot doesn't reverse. It just retreas without changing the direction.</b></pre>




#### Color Tests

+  _2_ / _2_ : Pass: Light is WHITE color?



+  _2_ / _2_ : Pass: Food is GREEN color?



+  _2_ / _2_ : Pass: Robot turns BLUE in given situation?
<pre>
<b>Comments: 
</b>You are changing the color based on the proximity of other entitity. It should be changed based on the light_behavior and food_behavior defined in the JSON config. </b></pre>



+  _2_ / _2_ : Pass: Robot turns MAROON in given situation?



+  _2_ / _2_ : Pass: Robot turns GOLD in given situation?



#### Total score: _19_ / _20_

