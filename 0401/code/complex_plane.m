% Parameters
a = 3;

figure;
hold on; grid on; axis equal;

% Real & Imag axes
plot([-4 4], [0 0], 'k', 'LineWidth', 1.2);
plot([0 0], [-4 4], 'k', 'LineWidth', 1.2);

% Red arrows
quiver(0, 0,  a, 0, 0, 'r', 'LineWidth', 2, 'MaxHeadSize', 0.5); % (a,0)
quiver(0, 0,  0, a, 0, 'r', 'LineWidth', 2, 'MaxHeadSize', 0.5); % (0,a)
quiver(0, 0, -a, 0, 0, 'r', 'LineWidth', 2, 'MaxHeadSize', 0.5); % (-a,0)

% Labels
text( a+0.1, 0,  '(a, 0)', 'FontSize', 12);
text( 0.1,  a,  '(0, a i)', 'FontSize', 12);
text(-a-0.5,0, '(-a, 0)', 'FontSize', 12);

% IEEE style
xlabel('Real Axis', 'FontSize', 12);
ylabel('Imaginary Axis', 'FontSize', 12);
title('Three Vectors in the Complex Plane', 'FontSize', 14);
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12, 'Box', 'on');

xlim([-4 4]);
ylim([-4 4]);

hold off;

% Save figure with 2000 DPI
print('complex_vectors','-dpng','-r2000');
