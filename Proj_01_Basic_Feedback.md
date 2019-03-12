### Feedback for Proj 01

Run on March 12, 18:18:36 PM.


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
Sufficient commits (found=55,required=25)

+ Pass: Run git ls-remote gather all branches in repo

c5221e5d87d86d9601cc01fb5e229e1202f6278b	refs/heads/devel

00fe9f39d5682f2869f3a5e85e878961887e50cf	refs/heads/feature/03-adding-tests

c5221e5d87d86d9601cc01fb5e229e1202f6278b	refs/heads/feature/priority-level-2

1aafd986340a9c11cf0dc85e39d85551dec705e2	refs/heads/fix/01-simulator-not-compiling

10f491f1cc086f5bb9e8edc4e1683dad693de517	refs/heads/fix/02-robots-stuck-in-walls

37b25b92d2d2e23a68d1f89da7183e9067035c3f	refs/heads/master




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 1)

[OPEN issue #/bin/sh:] : ghi: command not found





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 1)

[CLOSED issue #/bin/sh:] : ghi: command not found






#### Documentation Tests

+ Fail: Check that file "docs/uml_design.pdf" exists.

     "docs/uml_design.pdf" not found.

+ Fail: Check that file "docs/design.pdf" exists.

     "docs/design.pdf" not found.


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-strob105/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-strob105/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:238:  Missing space after ,  [whitespace/comma] [3]
arena.cc:46:  Add #include <string> for string  [build/include_what_you_use] [4]
braitenberg_vehicle.cc:48:  At least two spaces is best between code and comments  [whitespace/comments] [2]
braitenberg_vehicle.cc:48:  Should have a space between // and comment  [whitespace/comments] [4]
braitenberg_vehicle.cc:49:  Missing space after ,  [whitespace/comma] [3]
braitenberg_vehicle.cc:51:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:51:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:163:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:168:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:173:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:173:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:175:  Missing space after ,  [whitespace/comma] [3]
braitenberg_vehicle.cc:176:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:178:  Missing space after ,  [whitespace/comma] [3]
braitenberg_vehicle.cc:181:  Missing space after ,  [whitespace/comma] [3]
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
factory.cc:14:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
factory.cc:17:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.cc:17:  Missing space before {  [whitespace/braces] [5]
factory.cc:19:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory.cc:19:  Should have a space between // and comment  [whitespace/comments] [4]
factory.cc:26:  Missing space after ,  [whitespace/comma] [3]
factory.cc:28:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.cc:30:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.cc:30:  Missing space before {  [whitespace/braces] [5]
factory.cc:35:  Missing space after ,  [whitespace/comma] [3]
factory.cc:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.cc:39:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.cc:39:  Missing space before {  [whitespace/braces] [5]
factory.cc:44:  Missing space after ,  [whitespace/comma] [3]
factory.cc:46:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.cc:42:  Add #include <string> for string  [build/include_what_you_use] [4]
graphics_arena_viewer.cc:39:  Missing spaces around =  [whitespace/operators] [4]
graphics_arena_viewer.cc:46:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
graphics_arena_viewer.cc:46:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
arena_entity.h:141:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
arena.h:52:  Zero-parameter constructors should not be marked explicit.  [runtime/explicit] [5]
arena.h:55:  Is this a non-const reference? If so, make const or use a pointer: json_object& arena_object  [runtime/references] [2]
behavior_enum.h:37:  Add #include <string> for string  [build/include_what_you_use] [4]
common.h:19:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:20:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:21:  Tab found; better to use spaces  [whitespace/tab] [1]
common.h:20:  Add #include <string> for string  [build/include_what_you_use] [4]
controller.h:95:  #endif line should be "#endif  // SRC_CONTROLLER_H_"  [build/header_guard] [5]
controller.h:69:  Should have a space between // and comment  [whitespace/comments] [4]
controller.h:72:  Should have a space between // and comment  [whitespace/comments] [4]
controller.h:76:  Should have a space between // and comment  [whitespace/comments] [4]
controller.h:80:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
entity_type.h:14:  Found C++ system header after other header. Should be: entity_type.h, c system, c++ system, other.  [build/include_order] [4]
factory.h:19:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.h:19:  You don't need a ; after a }  [readability/braces] [4]
factory.h:21:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.h:21:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
factory.h:22:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.h:22:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
factory.h:23:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory.h:23:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
graphics_arena_viewer.h:171:  "virtual" is redundant since function is already declared as "override"  [readability/inheritance] [4]
pose.h:67:  Missing spaces around ==  [whitespace/operators] [3]
pose.h:76:  Missing spaces around !=  [whitespace/operators] [3]
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
Total errors found: 62
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

