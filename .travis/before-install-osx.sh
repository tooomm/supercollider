#!/bin/sh

export HOMEBREW_NO_AUTO_UPDATE=1
brew outdated cmake || brew upgrade cmake

# according to https://docs.travis-ci.com/user/caching#ccache-cache
brew install ccache libsndfile readline
export PATH="/usr/local/opt/ccache/libexec:$PATH"

brew install qt55 || true
brew link qt55 --force
