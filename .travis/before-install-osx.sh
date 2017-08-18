#!/bin/sh

brew update
brew tap homebrew/versions # this can be removed - qt55 was migrated to core
brew outdated cmake || brew upgrade cmake
brew install libsndfile python || true # python is already installed. this can also be specified in main matrix
brew install qt55 || true
brew link qt55 --force
