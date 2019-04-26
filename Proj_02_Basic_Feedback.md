### Feedback for Proj 02

Run on April 26, 14:22:14 PM.


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

13311b374bb6905c9efd3c090e90182f12575d1e	refs/heads/devel

378b0f72709749d7896d104e552f1b698a823eb5	refs/heads/feature/02-BV-sensor

00fe9f39d5682f2869f3a5e85e878961887e50cf	refs/heads/feature/03-adding-tests

edc2eecd5d74f74cbfb3d5fdb60ee5b4edf8bf9d	refs/heads/feature/04-strategy-pattern-implementation

4900658fd1bb523497000d3b20dcf1ee259df3de	refs/heads/feature/05-dynamic-color-additions

06f3fa356b6fe8faa2e68c42199b3eff9d6e860b	refs/heads/feature/06-observer-pattern

fc776e7bba32f65c7bbf6559823b06529e4fdcf2	refs/heads/feature/07-BV-predator-class

948eb8bd5aae33cba666e0188512c8997b714631	refs/heads/feature/08-braitenberg-starvation

72e3195f40b852a8f54384d3afb069d821c3ea96	refs/heads/feature/09-dynamic-wheel-velocity

13311b374bb6905c9efd3c090e90182f12575d1e	refs/heads/feature/10-predator-decorator-pattern

9797843cfda642b4da48dbe68052155448efdd0d	refs/heads/feature/iteration-2-checklist

6629d81c5c75c8e54ff7d64dd347f5f7bb612ef2	refs/heads/feature/priority-level-2

1aafd986340a9c11cf0dc85e39d85551dec705e2	refs/heads/fix/01-simulator-not-compiling

10f491f1cc086f5bb9e8edc4e1683dad693de517	refs/heads/fix/02-robots-stuck-in-walls

3204c5dde8d0ebc09252cf7db0c690c819983576	refs/heads/fix/05-predators-segfault-on-wall-collision

50cdc13b201b5669dff5f655dbfc0bbf2dbb8e1d	refs/heads/master

a744fddf2760036ad7d415132103c6727b725834	refs/heads/pre-release/iteration1

912db89d2eeb5e561665fc83eb66e25bddcfca04	refs/heads/pre-release/iteration2

cd25fdc074663860d170ad3f2becfc88c15b7f27	refs/heads/release/iteration1

642ef4faa68814046d671681b91ae70191160133	refs/heads/release/iteration2

a6a0a49913cd35245e523130dc71153f6d78aeb7	refs/heads/release/iteration2-prelim1

9130d8b68b116a042d40e06c25b5256b890243d4	refs/heads/release/iteration2-prelim2




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 8)

[OPEN issue #16] :  bug/08-predators-eating-predators

[OPEN issue #15] :  Food respawn  [enhancement]

[OPEN issue #13] :  bug/07-memory-leak-behaviors [bug]

[OPEN issue #12] :  bug/06-segfault-on-entity-choice-switch [bug] 1

[OPEN issue #10] :  Make factories for behaviors  [enhancement] 1

[OPEN issue #9] :  bug/04-robots-sometimes-stuck-in-corners [bug] [enhancement]

[OPEN issue #7] :  Change ugly json implementation in factory_unittests. See attached image. [enhancement] 1

[OPEN issue #6] :  Add: functionality to change color based braitenberg sensor influence. [enhancement] 1





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 8)

[CLOSED issue #14] :  Make factories for Predators

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
arena.cc:138:  Missing space before ( in if(  [whitespace/parens] [5]
arena.cc:141:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
arena.cc:141:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
arena.cc:173:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
braitenberg_predator.cc:53:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:53:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:54:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:55:  Missing space after ,  [whitespace/comma] [3]
braitenberg_predator.cc:57:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_predator.cc:57:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:59:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_predator.cc:59:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:61:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_predator.cc:61:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:62:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:63:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:63:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:64:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:65:  Missing space after ,  [whitespace/comma] [3]
braitenberg_predator.cc:67:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_predator.cc:67:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:69:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_predator.cc:69:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:88:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:91:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:91:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:92:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:94:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_predator.cc:97:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_predator.cc:97:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_predator.cc:97:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:98:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_predator.cc:107:  Consider using rand_r(...) instead of rand(...) for improved thread safety.  [runtime/threadsafe_fn] [2]
braitenberg_predator.cc:110:  Missing space before ( in switch(  [whitespace/parens] [5]
braitenberg_predator.cc:110:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:122:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_predator.cc:129:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:129:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:130:  Missing space before ( in for(  [whitespace/parens] [5]
braitenberg_predator.cc:130:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:131:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:131:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.cc:139:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:141:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:143:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:147:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:151:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:154:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:158:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.cc:158:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:319:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:320:  Consider using rand_r(...) instead of rand(...) for improved thread safety.  [runtime/threadsafe_fn] [2]
braitenberg_vehicle.cc:321:  Consider using rand_r(...) instead of rand(...) for improved thread safety.  [runtime/threadsafe_fn] [2]
braitenberg_vehicle.cc:322:  Consider using rand_r(...) instead of rand(...) for improved thread safety.  [runtime/threadsafe_fn] [2]
factory.cc:37:  Missing space before {  [whitespace/braces] [5]
factory.cc:48:  Missing space before {  [whitespace/braces] [5]
braitenberg_predator.h:83:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_predator.h:83:  Missing space before {  [whitespace/braces] [5]
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
Done processing mainpage.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing observer.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 58
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

