### Feedback for Proj 01

Run on March 14, 18:28:48 PM.


***Note: This is just the basic feedback.  The full feedback is run daily as a batch process (click link below)***


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Git Usage

+ Pass: Check git commit history
Commits found=74

+ Pass: Run git ls-remote gather all branches in repo

6629d81c5c75c8e54ff7d64dd347f5f7bb612ef2	refs/heads/devel

00fe9f39d5682f2869f3a5e85e878961887e50cf	refs/heads/feature/03-adding-tests

6629d81c5c75c8e54ff7d64dd347f5f7bb612ef2	refs/heads/feature/priority-level-2

1aafd986340a9c11cf0dc85e39d85551dec705e2	refs/heads/fix/01-simulator-not-compiling

10f491f1cc086f5bb9e8edc4e1683dad693de517	refs/heads/fix/02-robots-stuck-in-walls

5850077ae79f7561bc9b85696e498c9bb7d004ff	refs/heads/master




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 3)

[OPEN issue #5] :  feature/05-factory-test-json [enhancement]

[OPEN issue #4] :  Feature/04-full-json-functionality [enhancement]

[OPEN issue #3] :  bug/03-love-acts-like-explore [bug]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 2)

[CLOSED issue #2] :  bug/02-robots-stuck-in-walls [bug] 1

[CLOSED issue #1] :  bug/01-simulator-not-compiling [bug] 1






#### Documentation Tests

+ Fail: Check that file "docs/uml_design.pdf" exists.

     "docs/uml_design.pdf" not found.


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-strob105/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-strob105/cpplint/cpplint.py --root=.. *.cc *.h
arena.h:53:  Zero-parameter constructors should not be marked explicit.  [runtime/explicit] [5]
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing controller.cc
Done processing factory.cc
Done processing food.cc
Done processing graphics_arena_viewer.cc
Done processing light.cc
Done processing main.cc
Done processing motion_behavior.cc
Done processing motion_behavior_differential.cc
Done processing rgb_color.cc
Done processing arena_entity.h
Done processing arena.h
Done processing arena_immobile_entity.h
Done processing arena_mobile_entity.h
Done processing arena_viewer.h
Done processing behavior_enum.h
Done processing braitenberg_vehicle.h
Done processing common.h
Done processing controller.h
Done processing entity_type.h
Done processing factory.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing light.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 1
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-strob105/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Compile Tests


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Unit Tests


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)

