#!/bin/sh

brew update
brew outdated cmake || brew upgrade cmake
brew install libsndfile || true
brew install qt55 || true
brew link qt55 --force
