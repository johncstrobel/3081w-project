### Feedback for Proj 01

Run on March 16, 03:25:32 AM.

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

+ Fail: Check that file "docs/uml_design.pdf" exists.

     "docs/uml_design.pdf" not found.

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


#### Git Usage

+ Pass: Check git commit history
Commits found=76

+ Pass: Run git ls-remote gather all branches in repo

a744fddf2760036ad7d415132103c6727b725834	refs/heads/devel

00fe9f39d5682f2869f3a5e85e878961887e50cf	refs/heads/feature/03-adding-tests

6629d81c5c75c8e54ff7d64dd347f5f7bb612ef2	refs/heads/feature/priority-level-2

1aafd986340a9c11cf0dc85e39d85551dec705e2	refs/heads/fix/01-simulator-not-compiling

10f491f1cc086f5bb9e8edc4e1683dad693de517	refs/heads/fix/02-robots-stuck-in-walls

a73cc2965e47e37b84cab2fe1338b31a69863c18	refs/heads/master




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 3)

[OPEN issue #5] :  feature/05-factory-test-json [enhancement]

[OPEN issue #4] :  Feature/04-full-json-functionality [enhancement]

[OPEN issue #3] :  bug/03-love-acts-like-explore [bug]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 2)

[CLOSED issue #2] :  bug/02-robots-stuck-in-walls [bug] 1

[CLOSED issue #1] :  bug/01-simulator-not-compiling [bug] 1






#### Style Tests

+ Pass: Ensuring code follows style guide.




#### Unit Tests

+ Pass: Check that file "build/bin/unittest" exists.

+ Pass: Check that a GoogleTest test passes.
    passes the test: InstBraitenbergVehicle.RobotMovesInEmptyScene.



