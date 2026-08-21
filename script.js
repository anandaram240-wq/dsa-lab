/* ============================================================
   script.js — DSA Lab Smart Study Guide
   ============================================================ */

// ======= COUNTDOWN TIMER TO EXAM =======
function updateCountdown() {
    const now = new Date();
    // Tomorrow 8:30 AM
    const exam = new Date();
    exam.setDate(exam.getDate() + 1);
    exam.setHours(8, 30, 0, 0);

    // If exam time hasn't passed today, use today
    const todayExam = new Date();
    todayExam.setHours(8, 30, 0, 0);
    if (todayExam > now) {
        exam.setDate(exam.getDate() - 1);
    }

    const diff = exam - now;
    if (diff <= 0) {
        document.getElementById('countdown').textContent = '🎉 EXAM TIME! All the best!';
        return;
    }

    const h = Math.floor(diff / 3600000);
    const m = Math.floor((diff % 3600000) / 60000);
    const s = Math.floor((diff % 60000) / 1000);

    const pad = n => String(n).padStart(2, '0');
    document.getElementById('countdown').textContent = `${pad(h)}h ${pad(m)}m ${pad(s)}s left`;

    // Color urgency
    const el = document.getElementById('countdown');
    if (h < 2) el.style.color = '#ef4444';
    else if (h < 5) el.style.color = '#f97316';
    else el.style.color = '#f59e0b';
}

setInterval(updateCountdown, 1000);
updateCountdown();

// ======= TOGGLE GROUP EXPAND/COLLAPSE =======
function toggleGroup(id) {
    const card = document.getElementById(id);
    card.classList.toggle('open');
}

// Auto-open first group on load
document.addEventListener('DOMContentLoaded', () => {
    ['g1','g2','g3','g4'].forEach(id => {
        document.getElementById(id).classList.add('open');
    });
});

// ======= CODE TABS =======
function showTab(tabId, group) {
    // Hide all tabs in this group
    const allTabs = document.querySelectorAll(`[id$="-code"]`);
    const allBtns = document.querySelectorAll('.tab-btn');

    // Find the parent viewer
    const activeTab = document.getElementById(tabId);
    const parentViewer = activeTab.closest('.code-viewer');

    // Hide all tabs in this viewer
    parentViewer.querySelectorAll('.tab-content').forEach(t => t.classList.remove('active'));
    parentViewer.querySelectorAll('.tab-btn').forEach(b => b.classList.remove('active'));

    // Show selected
    activeTab.classList.add('active');

    // Find which button to activate (the one that called showTab with this tabId)
    parentViewer.querySelectorAll('.tab-btn').forEach(btn => {
        if (btn.getAttribute('onclick') && btn.getAttribute('onclick').includes(tabId)) {
            btn.classList.add('active');
        }
    });
}

// ======= SMOOTH SCROLL TO GROUP =======
document.querySelectorAll('.prog-tag').forEach(tag => {
    tag.style.cursor = 'pointer';
});

// ======= PROGRESS TRACKING =======
const STORAGE_KEY = 'dsa_study_progress';

function getProgress() {
    try {
        return JSON.parse(localStorage.getItem(STORAGE_KEY)) || {};
    } catch { return {}; }
}

function saveProgress(data) {
    try { localStorage.setItem(STORAGE_KEY, JSON.stringify(data)); } catch {}
}

// Mark groups as studied
document.querySelectorAll('.group-header').forEach(header => {
    const groupId = header.parentElement.id;
    const progress = getProgress();

    // Add checkmark if already studied
    if (progress[groupId]) {
        header.style.opacity = '0.7';
        const badge = header.querySelector('.group-badge');
        if (badge) badge.textContent += ' ✓';
    }

    header.addEventListener('dblclick', (e) => {
        e.stopPropagation();
        const p = getProgress();
        p[groupId] = !p[groupId];
        saveProgress(p);
        const badge = header.querySelector('.group-badge');
        if (p[groupId]) {
            header.style.opacity = '0.65';
            if (badge && !badge.textContent.includes('✓')) badge.textContent += ' ✓';
        } else {
            header.style.opacity = '1';
            if (badge) badge.textContent = badge.textContent.replace(' ✓', '');
        }
    });
});

// ======= ADD "MARK DONE" HINT =======
document.addEventListener('DOMContentLoaded', () => {
    const hint = document.createElement('div');
    hint.style.cssText = `
        position: fixed; bottom: 20px; right: 20px;
        background: rgba(18,18,26,0.95); border: 1px solid rgba(255,255,255,0.1);
        color: #888; font-size: 0.75rem; padding: 10px 14px; border-radius: 10px;
        font-family: Inter, sans-serif; z-index: 999;
        backdrop-filter: blur(10px);
        animation: fadeInHint 0.5s ease 2s both;
    `;
    hint.innerHTML = '💡 Double-click any group header to mark it done';

    const style = document.createElement('style');
    style.textContent = `@keyframes fadeInHint { from { opacity:0; transform:translateY(10px); } to { opacity:1; transform:none; } }`;
    document.head.appendChild(style);

    document.body.appendChild(hint);
    setTimeout(() => {
        hint.style.transition = 'opacity 0.5s';
        hint.style.opacity = '0';
        setTimeout(() => hint.remove(), 500);
    }, 6000);
});

// ======= KEYBOARD SHORTCUT (press 1-4 to jump to group) =======
document.addEventListener('keydown', (e) => {
    const map = { '1': 'g1', '2': 'g2', '3': 'g3', '4': 'g4' };
    if (map[e.key]) {
        const el = document.getElementById(map[e.key]);
        el.scrollIntoView({ behavior: 'smooth', block: 'start' });
        el.classList.add('open');
    }
});
