#!/bin/bash
ifconfig -a | grep -o -E 'ether [^ ]+' | awk '{print $2}'
