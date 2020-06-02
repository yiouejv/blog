mkdocs build
git status -s
git add .
git commit -m "$1"
git push
mkdocs serve
