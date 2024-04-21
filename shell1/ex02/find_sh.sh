#!/bin/bash
#find . -name "*.sh" 
find . -name "*.sh" -print0 | xargs -0 -I {} basename {} .sh
