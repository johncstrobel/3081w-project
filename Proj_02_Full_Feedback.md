### Feedback for Proj 02

Run on April 15, 02:25:17 AM.

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Compile Tests

+ Pass: Clean project.



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/arenaviewer" exists.


#### Documentation Tests

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


#### Git Usage

+ Pass: Check git commit history
Commits found=76

+ Pass: Run git ls-remote gather all branches in repo

912db89d2eeb5e561665fc83eb66e25bddcfca04	refs/heads/devel

378b0f72709749d7896d104e552f1b698a823eb5	refs/heads/feature/02-BV-sensor

00fe9f39d5682f2869f3a5e85e878961887e50cf	refs/heads/feature/03-adding-tests

edc2eecd5d74f74cbfb3d5fdb60ee5b4edf8bf9d	refs/heads/feature/04-strategy-pattern-implementation

4900658fd1bb523497000d3b20dcf1ee259df3de	refs/heads/feature/05-dynamic-color-additions

06f3fa356b6fe8faa2e68c42199b3eff9d6e860b	refs/heads/feature/06-observer-pattern

fc776e7bba32f65c7bbf6559823b06529e4fdcf2	refs/heads/feature/07-BV-predator-class

948eb8bd5aae33cba666e0188512c8997b714631	refs/heads/feature/08-braitenberg-starvation

72e3195f40b852a8f54384d3afb069d821c3ea96	refs/heads/feature/09-dynamic-wheel-velocity

b90b575fc0d4ce935d68a83382679e2599d17fda	refs/heads/feature/iteration-2-checklist

6629d81c5c75c8e54ff7d64dd347f5f7bb612ef2	refs/heads/feature/priority-level-2

1aafd986340a9c11cf0dc85e39d85551dec705e2	refs/heads/fix/01-simulator-not-compiling

10f491f1cc086f5bb9e8edc4e1683dad693de517	refs/heads/fix/02-robots-stuck-in-walls

3204c5dde8d0ebc09252cf7db0c690c819983576	refs/heads/fix/05-predators-segfault-on-wall-collision

48056147dd3c84baf8ddee429daacca17df25dcc	refs/heads/master

a744fddf2760036ad7d415132103c6727b725834	refs/heads/pre-release/iteration1

cd25fdc074663860d170ad3f2becfc88c15b7f27	refs/heads/release/iteration1

a6a0a49913cd35245e523130dc71153f6d78aeb7	refs/heads/release/iteration2-prelim1

9130d8b68b116a042d40e06c25b5256b890243d4	refs/heads/release/iteration2-prelim2




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 6)

[OPEN issue #13] :  bug/06-memory-leak-behaviors [bug]

[OPEN issue #12] :  bug/06-segfault-on-entity-choice-switch [bug] 1

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






#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_02_Full_Feedback/repo-strob105/project/src'
==== Checking style is correct ====
/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_02_Full_Feedback/repo-strob105/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:104:  Missing space before {  [whitespace/braces] [5]
arena.cc:105:  Missing space before ( in for(  [whitespace/parens] [5]
braitenberg_vehicle.cc:190:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:191:  Should have a space between // and comment  [whitespace/comments] [4]
braitenberg_vehicle.cc:212:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
Done processing arena.cc
Done processing behavior_aggressive.cc
Done processing behavior_coward.cc
Done processing behavior_explore.cc
Done processing behavior_love.cc
Done processing behavior_none.cc
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
Total errors found: 5
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_02_Full_Feedback/repo-strob105/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Unit Tests

+ Pass: Check that file "build/bin/unittest" exists.

+ Pass: Check that a GoogleTest test passes.
    passes the test: InstProj02.TestsRun.



