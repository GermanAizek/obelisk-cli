-- List of all groups
groups = {
    "general",
    "globals",
    "default"
}

for k,v in ipairs(groups) do
    CreateGroup(v)
end
