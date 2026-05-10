<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>Embedded SWE Interview Prep</title>
<link rel="preconnect" href="https://fonts.googleapis.com" />
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
<link href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;500;600&family=Syne:wght@400;500;700;800&display=swap" rel="stylesheet" />
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@tabler/icons-webfont@latest/tabler-icons.min.css" />
<style>
  *, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }

  :root {
    --bg: #0e0f11;
    --surface: #16181c;
    --surface2: #1e2128;
    --border: rgba(255,255,255,0.07);
    --border2: rgba(255,255,255,0.13);
    --text: #e8eaf0;
    --muted: #7a7f8e;
    --accent: #5de6a8;
    --accent2: #4fc8ff;
    --tag-bg: rgba(93,230,168,0.1);
    --font-display: 'Syne', sans-serif;
    --font-mono: 'JetBrains Mono', monospace;
  }

  html { scroll-behavior: smooth; }
  body { background: var(--bg); color: var(--text); font-family: var(--font-display); min-height: 100vh; }

  /* HERO */
  .hero {
    padding: 3rem 2.5rem 2rem;
    border-bottom: 1px solid var(--border);
    position: relative;
    overflow: hidden;
  }
  .hero::before {
    content: '';
    position: absolute;
    top: -80px; right: -80px;
    width: 380px; height: 380px;
    background: radial-gradient(circle, rgba(93,230,168,0.07) 0%, transparent 70%);
    pointer-events: none;
  }
  .hero-label {
    font-family: var(--font-mono);
    font-size: 11px;
    color: var(--accent);
    letter-spacing: 0.15em;
    text-transform: uppercase;
    margin-bottom: 0.75rem;
  }
  .hero h1 {
    font-size: clamp(1.8rem, 4vw, 2.6rem);
    font-weight: 800;
    line-height: 1.15;
    letter-spacing: -0.02em;
    margin-bottom: 0.6rem;
  }
  .hero h1 span { color: var(--accent); }
  .hero p {
    font-size: 13px;
    color: var(--muted);
    font-family: var(--font-mono);
    margin-bottom: 1.75rem;
  }
  .stats-row { display: flex; gap: 1rem; flex-wrap: wrap; }
  .stat {
    background: var(--surface);
    border: 1px solid var(--border);
    border-radius: 8px;
    padding: 0.5rem 1.1rem;
    text-align: center;
  }
  .stat-num { font-size: 1.25rem; font-weight: 700; color: var(--accent); }
  .stat-label { font-size: 10px; color: var(--muted); font-family: var(--font-mono); }

  /* SEARCH BAR */
  .search-bar {
    padding: 0.9rem 2.5rem;
    border-bottom: 1px solid var(--border);
    display: flex;
    gap: 0.75rem;
    align-items: center;
    flex-wrap: wrap;
    position: sticky;
    top: 0;
    z-index: 10;
    background: var(--bg);
  }
  .search-wrap {
    flex: 1; min-width: 180px;
    display: flex;
    align-items: center;
    gap: 8px;
    background: var(--surface);
    border: 1px solid var(--border2);
    border-radius: 8px;
    padding: 0 1rem;
  }
  .search-wrap i { color: var(--muted); font-size: 16px; }
  .search-wrap input {
    background: transparent;
    border: none;
    outline: none;
    color: var(--text);
    font-family: var(--font-mono);
    font-size: 13px;
    padding: 0.55rem 0;
    width: 100%;
  }
  .search-wrap input::placeholder { color: var(--muted); }
  .filter-pills { display: flex; gap: 6px; flex-wrap: wrap; }
  .pill {
    font-family: var(--font-mono);
    font-size: 11px;
    padding: 5px 12px;
    border-radius: 20px;
    border: 1px solid var(--border2);
    background: transparent;
    color: var(--muted);
    cursor: pointer;
    transition: all 0.15s;
    white-space: nowrap;
  }
  .pill:hover { border-color: var(--accent); color: var(--accent); }
  .pill.active { background: var(--tag-bg); border-color: var(--accent); color: var(--accent); }

  /* LAYOUT */
  .main {
    display: grid;
    grid-template-columns: 230px 1fr;
  }

  /* SIDEBAR */
  .sidebar {
    border-right: 1px solid var(--border);
    padding: 1.25rem 0;
    position: sticky;
    top: 57px;
    height: calc(100vh - 57px);
    overflow-y: auto;
  }
  .sidebar::-webkit-scrollbar { width: 4px; }
  .sidebar::-webkit-scrollbar-track { background: transparent; }
  .sidebar::-webkit-scrollbar-thumb { background: var(--border2); border-radius: 2px; }

  .sidebar-title {
    font-family: var(--font-mono);
    font-size: 10px;
    color: var(--muted);
    letter-spacing: 0.12em;
    text-transform: uppercase;
    padding: 0 1.25rem;
    margin-bottom: 0.75rem;
  }
  .cat-btn {
    display: flex;
    align-items: center;
    justify-content: space-between;
    width: 100%;
    padding: 0.5rem 1.25rem;
    background: transparent;
    border: none;
    border-left: 2px solid transparent;
    color: var(--muted);
    font-family: var(--font-display);
    font-size: 13px;
    font-weight: 500;
    cursor: pointer;
    text-align: left;
    transition: all 0.12s;
  }
  .cat-btn:hover { color: var(--text); background: var(--surface); }
  .cat-btn.active { color: var(--accent); border-left-color: var(--accent); background: var(--surface); }
  .cat-count {
    font-family: var(--font-mono);
    font-size: 10px;
    background: var(--surface2);
    border-radius: 10px;
    padding: 2px 7px;
    color: var(--muted);
    flex-shrink: 0;
  }
  .cat-btn.active .cat-count { background: var(--tag-bg); color: var(--accent); }

  /* CONTENT */
  .content { padding: 1.75rem 2.5rem; }

  .section { margin-bottom: 2.75rem; display: none; }
  .section.visible { display: block; }

  .section-header {
    display: flex;
    align-items: center;
    gap: 0.75rem;
    margin-bottom: 0.5rem;
    padding-bottom: 0.75rem;
    border-bottom: 1px solid var(--border);
  }
  .section-icon {
    width: 32px; height: 32px;
    border-radius: 8px;
    display: flex; align-items: center; justify-content: center;
    font-size: 16px;
    flex-shrink: 0;
  }
  .section-header h2 {
    font-size: 1rem;
    font-weight: 700;
    letter-spacing: -0.01em;
  }
  .section-badge {
    font-family: var(--font-mono);
    font-size: 10px;
    padding: 2px 8px;
    border-radius: 10px;
    background: rgba(255,255,255,0.05);
    color: var(--muted);
    margin-left: auto;
  }

  .progress-bar-wrap {
    display: flex; align-items: center; gap: 10px;
    margin-bottom: 1rem;
  }
  .progress-bar {
    flex: 1; height: 3px;
    background: var(--surface2);
    border-radius: 2px;
    overflow: hidden;
  }
  .progress-fill {
    height: 100%;
    background: var(--accent);
    border-radius: 2px;
    transition: width 0.3s ease;
  }
  .progress-label {
    font-family: var(--font-mono);
    font-size: 10px;
    color: var(--muted);
    white-space: nowrap;
  }

  /* TOPIC CARDS */
  .topics-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(290px, 1fr));
    gap: 8px;
  }
  .topic-card {
    background: var(--surface);
    border: 1px solid var(--border);
    border-radius: 8px;
    padding: 0.65rem 1rem;
    display: flex;
    align-items: flex-start;
    gap: 10px;
    transition: all 0.15s;
    cursor: default;
  }
  .topic-card:hover { border-color: var(--border2); background: var(--surface2); }
  .topic-card.done { opacity: 0.4; }
  .topic-card.done .topic-text { text-decoration: line-through; }

  .check-box {
    width: 16px; height: 16px;
    border: 1px solid var(--border2);
    border-radius: 4px;
    flex-shrink: 0;
    margin-top: 2px;
    cursor: pointer;
    display: flex; align-items: center; justify-content: center;
    transition: all 0.12s;
    font-size: 10px;
    color: transparent;
    user-select: none;
  }
  .topic-card:hover .check-box { border-color: var(--accent); }
  .topic-card.done .check-box { background: var(--accent); border-color: var(--accent); color: #000; font-weight: 700; }

  .topic-text {
    font-size: 13px;
    line-height: 1.55;
    color: var(--text);
    flex: 1;
  }
  .g75-badge {
    font-family: var(--font-mono);
    font-size: 9px;
    padding: 1px 5px;
    border-radius: 4px;
    background: rgba(79,200,255,0.12);
    color: var(--accent2);
    border: 1px solid rgba(79,200,255,0.2);
    flex-shrink: 0;
    margin-top: 3px;
    white-space: nowrap;
  }

  .no-results {
    padding: 4rem;
    text-align: center;
    color: var(--muted);
    font-family: var(--font-mono);
    font-size: 13px;
    display: none;
  }

  /* FOOTER */
  footer {
    border-top: 1px solid var(--border);
    padding: 1.25rem 2.5rem;
    display: flex;
    align-items: center;
    justify-content: space-between;
    flex-wrap: wrap;
    gap: 0.5rem;
  }
  footer span {
    font-family: var(--font-mono);
    font-size: 11px;
    color: var(--muted);
  }
  footer a {
    font-family: var(--font-mono);
    font-size: 11px;
    color: var(--accent);
    text-decoration: none;
  }
  footer a:hover { text-decoration: underline; }

  /* RESPONSIVE */
  @media (max-width: 700px) {
    .hero { padding: 2rem 1.25rem 1.5rem; }
    .search-bar { padding: 0.75rem 1.25rem; }
    .main { grid-template-columns: 1fr; }
    .sidebar {
      position: static;
      height: auto;
      border-right: none;
      border-bottom: 1px solid var(--border);
      padding: 0.75rem 1rem;
      display: flex;
      flex-wrap: wrap;
      gap: 4px;
      overflow: visible;
    }
    .sidebar-title { display: none; }
    .cat-btn {
      border-left: none;
      border: 1px solid var(--border);
      border-radius: 6px;
      padding: 0.35rem 0.75rem;
      width: auto;
      font-size: 12px;
    }
    .cat-btn.active { border-color: var(--accent); }
    .content { padding: 1.25rem; }
    .topics-grid { grid-template-columns: 1fr; }
    footer { padding: 1rem 1.25rem; }
  }
</style>
</head>
<body>

<div id="app">
  <header class="hero">
    <div class="hero-label">// interview prep</div>
    <h1>Embedded <span>SW Engineering</span><br>Interview Guide</h1>
    <p>Linked lists to linkers. Mutexes to memory models.</p>
    <div class="stats-row" id="stats-row"></div>
  </header>

  <div class="search-bar">
    <div class="search-wrap">
      <i class="ti ti-search" aria-hidden="true"></i>
      <input type="text" placeholder="Search topics..." id="search-input" aria-label="Search topics" />
    </div>
    <div class="filter-pills" role="group" aria-label="Filter topics">
      <button class="pill active" data-filter="all">All</button>
      <button class="pill" data-filter="g75">G75 only</button>
      <button class="pill" data-filter="todo">To do</button>
      <button class="pill" data-filter="done">Done</button>
    </div>
  </div>

  <div class="main">
    <nav class="sidebar" id="sidebar" aria-label="Categories"></nav>
    <main class="content" id="content">
      <div class="no-results" id="no-results" role="status">No matching topics found.</div>
    </main>
  </div>

  <footer>
    <span>Progress saved in your browser &mdash; <span id="footer-progress"></span></span>
    <a href="https://www.techinterviewhandbook.org/grind75" target="_blank" rel="noopener">Grind 75 &rarr;</a>
  </footer>
</div>

<script>
const DATA = {
  "Linked List": {
    icon: "ti-list",
    color: "#5de6a8",
    iconBg: "rgba(93,230,168,0.12)",
    items: [
      { text: "Determine if there is a cycle or not" },
      { text: "Return the node where a cycle begins" },
      { text: "Find the node where two linked lists intersect" },
      { text: "Remove Nth node from end of the list" },
      { text: "Reverse linked list" },
      { text: "Remove linked list elements of a given value" },
      { text: "Group all odd and even nodes together in order" },
      { text: "Palindrome linked list" },
      { text: "Merge two sorted linked lists" },
      { text: "Insert into a cyclic sorted linked list" },
      { text: "Rotate linked list by K places" },
      { text: "XOR linked list" },
      { text: "Reverse linked list in blocks of K" },
      { text: "Add a node at nth position" },
      { text: "Delete a node from nth position" },
      { text: "Delete a particular node from the linked list" },
    ]
  },
  "Arrays": {
    icon: "ti-table",
    color: "#4fc8ff",
    iconBg: "rgba(79,200,255,0.12)",
    items: [
      { text: "Find pivot index (sum left = sum right)" },
      { text: "Diagonal traverse and print" },
      { text: "Spiral matrix" },
      { text: "Implement strstr()" },
      { text: "Two pointer technique — reverse string, array partition" },
      { text: "Two pointer fast/slow — remove element, max consecutive 1s, min subarray sum, rotate array" },
      { text: "Reverse words in a string (word-by-word, within-word)" },
      { text: "Remove duplicates from sorted array" },
      { text: "Move all zeroes to the end" },
      { text: "Max subarray sum — DP" },
      { text: "Find K closest elements to a given value" },
    ]
  },
  "Hashmap": {
    icon: "ti-hash",
    color: "#ff7a5c",
    iconBg: "rgba(255,122,92,0.12)",
    items: [
      { text: "2 Sum — return indices adding to target", g75: true },
      { text: "4 Sum" },
      { text: "Find all duplicates" },
      { text: "Intersection of 2 arrays" },
      { text: "Isomorphic strings" },
      { text: "First unique character in a string (one pass, two pass)" },
      { text: "Group anagrams" },
      { text: "Valid Sudoku" },
      { text: "Longest substring without repeating characters" },
      { text: "LRU cache", g75: true },
      { text: "Ransom Note", g75: true },
      { text: "Insert Delete GetRandom O(1)", g75: true },
      { text: "Design Hashmap" },
    ]
  },
  "Stack": {
    icon: "ti-stack-2",
    color: "#c084fc",
    iconBg: "rgba(192,132,252,0.12)",
    items: [
      { text: "Implement Stack using an Array" },
      { text: "Implement Stack using a Linked List" },
      { text: "Implement Queue using Stack", g75: true },
      { text: "Valid (Balanced) Parentheses", g75: true },
      { text: "Backspace String Compare", g75: true },
      { text: "Evaluate Reverse Polish Notation", g75: true },
      { text: "Min Stack", g75: true },
      { text: "Daily Temperature", g75: true },
      { text: "Decode String", g75: true },
      { text: "Asteroid Collision", g75: true },
      { text: "Basic Calculator II", g75: true },
      { text: "Trapping Rain Water", g75: true },
    ]
  },
  "Queue": {
    icon: "ti-arrows-right",
    color: "#facc15",
    iconBg: "rgba(250,204,21,0.12)",
    items: [
      { text: "Implement Queue using an Array" },
      { text: "Implement Queue using a Linked List" },
      { text: "Implement Stack using Queue" },
      { text: "Circular (Ring) buffer" },
      { text: "Design Hit Counter", g75: true },
    ]
  },
  "Sorting": {
    icon: "ti-arrows-sort",
    color: "#5de6a8",
    iconBg: "rgba(93,230,168,0.12)",
    items: [
      { text: "Selection sort" },
      { text: "Bubble sort" },
      { text: "Insertion sort" },
      { text: "Merge sort" },
      { text: "Quick sort" },
    ]
  },
  "Searching": {
    icon: "ti-zoom-code",
    color: "#4fc8ff",
    iconBg: "rgba(79,200,255,0.12)",
    items: [
      { text: "Linear search" },
      { text: "Binary search" },
    ]
  },
  "Bit Manipulation": {
    icon: "ti-binary",
    color: "#ff7a5c",
    iconBg: "rgba(255,122,92,0.12)",
    items: [
      { text: "Swap bits in odd and even positions" },
      { text: "Power of 2" },
      { text: "Set, clear and toggle i'th bit" },
      { text: "Find position of the only set bit" },
      { text: "Count number of set bits in logN time" },
      { text: "Add two numbers without arithmetic operators", g75: true },
      { text: "Find the only number that appears once", g75: true },
      { text: "Set all bits in a given range" },
      { text: "Compute 2's complement" },
      { text: "Position of rightmost bit set" },
      { text: "Isolate the rightmost bit set" },
      { text: "Toggle rightmost bit set" },
      { text: "Position of leftmost bit set" },
      { text: "Swap 2 numbers without a temporary variable" },
      { text: "Reverse the order of bits in a number" },
      { text: "Modify a bit at a given position to 1 or 0" },
      { text: "Missing Number", g75: true },
      { text: "Number of 1 bits", g75: true },
      { text: "Counting bits", g75: true },
      { text: "Find the duplicate number", g75: true },
    ]
  },
  "Embedded Specific": {
    icon: "ti-cpu",
    color: "#c084fc",
    iconBg: "rgba(192,132,252,0.12)",
    items: [
      { text: "Boot sequence" },
      { text: "Causes of segmentation fault and how to overcome" },
      { text: "Differences between fault, abort and trap" },
      { text: "Compiler, assembler, linker, loader" },
      { text: "Volatile, preprocessor, pragmas, const" },
      { text: "Fine-grained vs coarse-grained multithreading" },
      { text: "Virtual memory, paging, thread vs process" },
      { text: "Implement mutex using test-and-set, load-linked & store-conditional" },
      { text: "Mutex vs semaphore" },
      { text: "Reader-writer mutex" },
      { text: "Producer-consumer problem" },
      { text: "Strict padding alignment" },
      { text: "Endianness — detect endianness, convert big ↔ little endian" },
      { text: "Implement memcpy, memmove, strstr, strcpy, atoi, malloc, free" },
      { text: "Aligned malloc" },
      { text: "VIPT, TLBs, page faults" },
      { text: "Interrupts, exceptions, deadlocks, priority inversion and inheritance" },
      { text: "HW breakpoint vs SW breakpoint" },
      { text: "SPI vs UART vs I2C" },
      { text: "Matrix multiplication, cache blocking, tiling, GEMM, matrix rotation" },
      { text: "Banker's algorithm, buddy system memory allocation, inverted paging" },
      { text: "Spinlocks, conditional variables" },
      { text: "Task scheduling, thrashing, cycle stealing, race conditions" },
      { text: "Queues, FIFO, Mailbox" },
      { text: "Bélády's anomaly, dining philosophers problem" },
      { text: "Security: digital signing, hash, encryption" },
      { text: "Firmware update" },
      { text: "Unit testing vs integration testing" },
      { text: "RTOS vs bare metal" },
      { text: "HW timer: build a SW timer API from a HW timer" },
      { text: "Function pointers and callbacks" },
    ]
  },
  "C++": {
    icon: "ti-code",
    color: "#facc15",
    iconBg: "rgba(250,204,21,0.12)",
    items: [
      { text: "new and delete operators" },
      { text: "OOP theory — abstraction, inheritance, polymorphism, encapsulation" },
      { text: "Inline functions" },
      { text: "Virtual functions, vptr and vtable" },
      { text: "Friend class and function" },
      { text: "Virtual base class, abstract class" },
      { text: "Function pointers" },
      { text: "Templates, template specialization, object slicing" },
      { text: "Deep vs shallow copy" },
      { text: "Copy constructors, constructor vs destructor" },
      { text: "Overloading vs overriding operators" },
      { text: "Different types of casting" },
      { text: "Static keyword, static functions" },
      { text: "Pointers vs references" },
      { text: "lvalue and rvalue" },
      { text: "Smart pointers" },
    ]
  }
};

const STORAGE_KEY = 'eswe_done_v1';
let done = {};
try { done = JSON.parse(localStorage.getItem(STORAGE_KEY) || '{}'); } catch(e) {}

let activeCategory = 'all';
let activeFilter = 'all';
let searchQuery = '';

function saveState() {
  try { localStorage.setItem(STORAGE_KEY, JSON.stringify(done)); } catch(e) {}
}

function itemKey(cat, idx) { return cat + '::' + idx; }

function totalItems() {
  return Object.values(DATA).reduce((s, c) => s + c.items.length, 0);
}
function totalDone() {
  return Object.keys(done).filter(k => done[k]).length;
}
function g75Count() {
  return Object.values(DATA).reduce((s, c) => s + c.items.filter(i => i.g75).length, 0);
}

function buildStats() {
  const row = document.getElementById('stats-row');
  row.innerHTML =
    '<div class="stat"><div class="stat-num">' + totalItems() + '</div><div class="stat-label">topics</div></div>' +
    '<div class="stat"><div class="stat-num">' + Object.keys(DATA).length + '</div><div class="stat-label">categories</div></div>' +
    '<div class="stat"><div class="stat-num">' + g75Count() + '</div><div class="stat-label">G75 picks</div></div>' +
    '<div class="stat" id="stat-done"><div class="stat-num" id="done-num">' + totalDone() + '</div><div class="stat-label">completed</div></div>';
}

function updateDoneStat() {
  const el = document.getElementById('done-num');
  if (el) el.textContent = totalDone();
  const fp = document.getElementById('footer-progress');
  if (fp) fp.textContent = totalDone() + ' of ' + totalItems() + ' topics completed';
}

function buildSidebar() {
  const sb = document.getElementById('sidebar');
  sb.innerHTML = '<div class="sidebar-title">Categories</div>';

  const allBtn = document.createElement('button');
  allBtn.className = 'cat-btn' + (activeCategory === 'all' ? ' active' : '');
  allBtn.innerHTML = 'All topics <span class="cat-count">' + totalItems() + '</span>';
  allBtn.onclick = function() { activeCategory = 'all'; render(); };
  sb.appendChild(allBtn);

  Object.entries(DATA).forEach(function([name, cat]) {
    const btn = document.createElement('button');
    btn.className = 'cat-btn' + (activeCategory === name ? ' active' : '');
    btn.innerHTML = name + ' <span class="cat-count">' + cat.items.length + '</span>';
    btn.onclick = function() { activeCategory = name; render(); };
    sb.appendChild(btn);
  });
}

function matchesFilter(cat, item, idx) {
  const key = itemKey(cat, idx);
  const isDone = !!done[key];
  if (activeFilter === 'g75' && !item.g75) return false;
  if (activeFilter === 'todo' && isDone) return false;
  if (activeFilter === 'done' && !isDone) return false;
  if (searchQuery) {
    if (!item.text.toLowerCase().includes(searchQuery.toLowerCase())) return false;
  }
  return true;
}

function buildSection(name, cat, offset) {
  const visibleItems = cat.items
    .map(function(item, i) { return { item: item, idx: i + offset }; })
    .filter(function(o) { return matchesFilter(name, o.item, o.idx); });

  if (!visibleItems.length) return null;

  const doneInCat = cat.items.filter(function(_, i) { return done[itemKey(name, i + offset)]; }).length;
  const pct = Math.round(doneInCat / cat.items.length * 100);

  const sec = document.createElement('div');
  sec.className = 'section visible';
  sec.id = 'sec-' + name.replace(/\s+/g, '-');

  sec.innerHTML =
    '<div class="section-header">' +
      '<div class="section-icon" style="background:' + cat.iconBg + '">' +
        '<i class="ti ' + cat.icon + '" style="color:' + cat.color + ';font-size:17px" aria-hidden="true"></i>' +
      '</div>' +
      '<h2>' + name + '</h2>' +
      '<span class="section-badge">' + cat.items.length + ' topics</span>' +
    '</div>' +
    '<div class="progress-bar-wrap">' +
      '<div class="progress-bar"><div class="progress-fill" style="width:' + pct + '%"></div></div>' +
      '<span class="progress-label">' + doneInCat + ' / ' + cat.items.length + '</span>' +
    '</div>' +
    '<div class="topics-grid"></div>';

  const grid = sec.querySelector('.topics-grid');
  visibleItems.forEach(function(o) {
    const item = o.item;
    const idx = o.idx;
    const key = itemKey(name, idx);
    const isDone = !!done[key];
    const card = document.createElement('div');
    card.className = 'topic-card' + (isDone ? ' done' : '');
    card.innerHTML =
      '<div class="check-box" role="checkbox" aria-checked="' + isDone + '" tabindex="0" title="Mark complete">' + (isDone ? '✓' : '') + '</div>' +
      '<span class="topic-text">' + item.text + '</span>' +
      (item.g75 ? '<span class="g75-badge" title="Grind 75 problem">G75</span>' : '');

    function toggle() {
      done[key] = !done[key];
      if (!done[key]) delete done[key];
      saveState();
      render();
    }

    const cb = card.querySelector('.check-box');
    cb.onclick = toggle;
    cb.onkeydown = function(e) { if (e.key === 'Enter' || e.key === ' ') { e.preventDefault(); toggle(); } };
    grid.appendChild(card);
  });

  return sec;
}

function render() {
  buildSidebar();
  const content = document.getElementById('content');
  const noResults = document.getElementById('no-results');

  content.querySelectorAll('.section').forEach(function(s) { s.remove(); });

  let offset = 0;
  let anyVisible = false;

  Object.entries(DATA).forEach(function([name, cat]) {
    if (activeCategory !== 'all' && activeCategory !== name) {
      offset += cat.items.length;
      return;
    }
    const sec = buildSection(name, cat, offset);
    if (sec) { content.appendChild(sec); anyVisible = true; }
    offset += cat.items.length;
  });

  noResults.style.display = anyVisible ? 'none' : 'block';
  updateDoneStat();
}

document.getElementById('search-input').addEventListener('input', function(e) {
  searchQuery = e.target.value.trim();
  if (searchQuery) activeCategory = 'all';
  render();
});

document.querySelectorAll('.pill').forEach(function(p) {
  p.addEventListener('click', function() {
    document.querySelectorAll('.pill').forEach(function(x) { x.classList.remove('active'); });
    p.classList.add('active');
    activeFilter = p.dataset.filter;
    render();
  });
});

buildStats();
render();
updateDoneStat();
</script>
</body>
</html>
