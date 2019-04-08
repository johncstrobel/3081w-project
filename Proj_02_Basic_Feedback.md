### Feedback for Proj 02

Run on April 08, 13:42:24 PM.


***Note: This is just the basic feedback.  The full feedback is run daily as a batch process (click link below)***


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)

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
Commits found=76

+ Pass: Run git ls-remote gather all branches in repo

975234dc78bd8af7a14a54203eaf54fc68f25c83	refs/heads/devel

378b0f72709749d7896d104e552f1b698a823eb5	refs/heads/feature/02-BV-sensor

00fe9f39d5682f2869f3a5e85e878961887e50cf	refs/heads/feature/03-adding-tests

edc2eecd5d74f74cbfb3d5fdb60ee5b4edf8bf9d	refs/heads/feature/04-strategy-pattern-implementation

d32cde48fe964f60f12fd6c550752b2da0dd698d	refs/heads/feature/05-dynamic-color-additions

06f3fa356b6fe8faa2e68c42199b3eff9d6e860b	refs/heads/feature/06-observer-pattern

fc776e7bba32f65c7bbf6559823b06529e4fdcf2	refs/heads/feature/07-BV-predator-class

6629d81c5c75c8e54ff7d64dd347f5f7bb612ef2	refs/heads/feature/priority-level-2

1aafd986340a9c11cf0dc85e39d85551dec705e2	refs/heads/fix/01-simulator-not-compiling

10f491f1cc086f5bb9e8edc4e1683dad693de517	refs/heads/fix/02-robots-stuck-in-walls

3204c5dde8d0ebc09252cf7db0c690c819983576	refs/heads/fix/05-predators-segfault-on-wall-collision

f148efcc874e38869a0e04aa5d1ef5e8d1d2b6df	refs/heads/master

a744fddf2760036ad7d415132103c6727b725834	refs/heads/pre-release/iteration1

cd25fdc074663860d170ad3f2becfc88c15b7f27	refs/heads/release/iteration1

a6a0a49913cd35245e523130dc71153f6d78aeb7	refs/heads/release/iteration2-prelim1




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 5)

[OPEN issue #12] :  bug/06-segfault-on-entity-choice-switch 1

[OPEN issue #10] :  Make factories for behaviors  [enhancement] 1

[OPEN issue #9] :  bug/04-robots-sometimes-stuck-in-corners [bug] [enhancement]

[OPEN issue #7] :  Change ugly json implementation in factory_unittests. See attached image. [enhancement] 1

[OPEN issue #6] :  Add: functionality to change color based braitenberg sensor influence. [enhancement] 1





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 7)

[CLOSED issue #11] :  bug/05-predators-segfault-on-wall-collision [bug]

[CLOSED issue #8] :  feature/02-BV-sensor [bug] 1

[CLOSED issue #5] :  feature/05-factory-test-json [enhancement] 1

[CLOSED issue #4] :  Feature/04-full-json-functionality [enhancement] 1

[CLOSED issue #3] :  bug/03-love-acts-like-explore [bug] 2

[CLOSED issue #2] :  bug/02-robots-stuck-in-walls [bug] 1

[CLOSED issue #1] :  bug/01-simulator-not-compiling [bug] 1






#### Documentation Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-strob105/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-strob105/cpplint/cpplint.py --root=.. *.cc *.h
braitenberg_observer.cc:34:  Missing space after ,  [whitespace/comma] [3]
braitenberg_observer.cc:35:  Missing space before {  [whitespace/braces] [5]
braitenberg_observer.cc:36:  Missing space before ( in for(  [whitespace/parens] [5]
braitenberg_observer.cc:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_observer.cc:37:  At least two spaces is best between code and comments  [whitespace/comments] [2]
braitenberg_observer.cc:37:  Should have a space between // and comment  [whitespace/comments] [4]
braitenberg_observer.cc:40:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_observer.cc:41:  Missing space before {  [whitespace/braces] [5]
braitenberg_observer.cc:42:  Missing space after ,  [whitespace/comma] [3]
braitenberg_observer.cc:55:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:190:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:191:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
braitenberg_vehicle.cc:226:  Missing space after ,  [whitespace/comma] [3]
braitenberg_vehicle.cc:257:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:262:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:263:  Missing space before ( in for(  [whitespace/parens] [5]
braitenberg_vehicle.cc:263:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:264:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:264:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:275:  You don't need a ; after a }  [readability/braces] [4]
braitenberg_vehicle.cc:272:  Missing space before ( in for(  [whitespace/parens] [5]
braitenberg_vehicle.cc:272:  Missing space after ;  [whitespace/semicolon] [3]
braitenberg_vehicle.cc:273:  Missing space after ,  [whitespace/comma] [3]
braitenberg_vehicle.cc:275:  At least two spaces is best between code and comments  [whitespace/comments] [2]
braitenberg_vehicle.cc:275:  Should have a space between // and comment  [whitespace/comments] [4]
graphics_arena_viewer.cc:44:  Missing space before {  [whitespace/braces] [5]
graphics_arena_viewer.cc:330:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:352:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:455:  Missing space before {  [whitespace/braces] [5]
behavior.h:49:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
behavior.h:50:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
behavior.h:50:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_observer.h:32:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_observer.h:34:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_observer.h:36:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_observer.h:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_observer.h:40:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_observer.h:41:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:230:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
graphics_arena_viewer.h:60:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.h:233:  "private:" should be preceded by a blank line  [whitespace/blank_line] [3]
graphics_arena_viewer.h:234:  Do not leave a blank line after "private:"  [whitespace/blank_line] [3]
graphics_arena_viewer.h:228:  Add #include <string> for string  [build/include_what_you_use] [4]
observer.h:32:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:32:  You don't need a ; after a }  [readability/braces] [4]
observer.h:33:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:33:  You don't need a ; after a }  [readability/braces] [4]
observer.h:35:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:36:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:38:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:41:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:41:  You don't need a ; after a }  [readability/braces] [4]
observer.h:43:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:44:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:47:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
observer.h:49:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
Done processing arena.cc
Done processing behavior_aggressive.cc
Done processing behavior_coward.cc
Done processing behavior_explore.cc
Done processing behavior_love.cc
Done processing behavior_none.cc
Done processing braitenberg_observer.cc
Done processing braitenberg_predator.cc
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
Done processing behavior_aggressive.h
Done processing behavior_coward.h
Done processing behavior_enum.h
Done processing behavior_explore.h
Done processing behavior.h
Done processing behavior_love.h
Done processing behavior_none.h
Done processing braitenberg_observer.h
Done processing braitenberg_predator.h
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
Done processing observer.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 56
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-strob105/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Compile Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)


#### Unit Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)

