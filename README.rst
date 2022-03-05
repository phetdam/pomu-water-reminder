.. README.rst

water-reminder
==============

A `Qt6`__ app that reminds you to drink your water.

.. __: https://www.qt.io/product/qt6

Icon attribution
----------------

``water.png``
   Icon made by Freepik_ from Flaticon_.
``water_fountain.png``
   Icon made by photo3idea_studio_ from Flaticon_.
``water_icon.png``
   Icon made by SBTS2018_ from Flaticon_.

.. _Flaticon: https://www.flaticon.com/

.. _Freepik: https://www.flaticon.com/authors/freepik

.. _photo3idea_studio: https://www.flaticon.com/authors/photo3idea-studio

.. _SBTS2018: https://www.flaticon.com/authors/sbts2018

Note for WSL users
------------------

.. _aqt: https://github.com/miurahr/aqtinstall

You may notice that in the Linux build [#]_, after using aqt_ to download Qt,
we run the command

.. code:: bash

   sudo strip --remove-section=.note.ABI-tag /path/to/Qt6/bin/libQtCore.so.6

Several people have run into an issue on WSL Ubuntu in loading
``libQt5Core.so.6``, which yields the error message

   cannot open shared object file: No such file or directory

`From an old Arch Linux thread`__, the root of the cause for Qt 5 seemed to be
the version of the kernel, as Qt 5 made a system call that only existed on
later versions of the Arch Linux kernel. It turns out that particular system
call is `also missing from WSL 1`__, so unless the above ``strip`` command is
run on ``libQt[5-6]Core.so.6``, one will get that same error message when
trying to run ``qmake``, ``designer``, etc.

.. __: https://bbs.archlinux.org/viewtopic.php?id=232682

.. __: https://superuser.com/a/1348051

Solution originally found from `this StackOverflow answer`__, which finally put
to an end a couple days' worth of torture and pain in trying to get Qt 6 to
work on WSL 1 Ubuntu. See also the corresponding `official WSL GitHub issue`__.

.. __: https://stackoverflow.com/a/64594256/14227825

.. __: https://github.com/microsoft/WSL/issues/3023

.. [#] No builds are available yet.