FROM archlinux

RUN pacman -Syu --noconfirm \
	git			\
	cmake			\
	make			\
	clang			\
	lldb			\
	boost			\
	boost-libs	\
	vim			\
	doxygen		\
	graphviz		\
	texlive		\
	texlive-langcyrillic
