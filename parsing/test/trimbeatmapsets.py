"""
Replaces unneeded files in a file tree with empty dummy files,
the purpose of which is to save precious space. Beatmap files (.osu)
are left untouched and all file names are preserved.
"""

import os


def trim(root):
    size_before, size_after = 0, 0
    for path, dirs, files in os.walk(root):
        for file in files:
            f = os.path.join(path, file)
            size_before += os.path.getsize(f)
            if not file.lower().endswith(".osu"):
                replace_with_dummy(f)
            size_after += os.path.getsize(f)
    return size_before, size_after


def replace_with_dummy(file):
    os.remove(file)
    open(file, 'w').close()


if __name__ == '__main__':
    beatmapsets_path = "./beatmapsets"
    before, after = trim(beatmapsets_path)
    print("Size before trimming: ", before)
    print("Size after trimming:  ", after)
