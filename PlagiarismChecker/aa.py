import os;
PROJECT_ROOT = os.path.abspath(os.path.dirname(__file__) + "../")
print PROJECT_ROOT
MEDIA_ROOT = os.path.join(PROJECT_ROOT, "media")
STATIC_ROOT = os.path.join(PROJECT_ROOT, "static")
print MEDIA_ROOT
print STATIC_ROOT