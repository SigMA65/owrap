TEMPLATE = subdirs

SUBDIRS += \
  build \
  test

test.depends = build


