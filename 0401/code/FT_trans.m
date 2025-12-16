% MATLAB code to generate a 3D figure similar to the one you described:
% Time-domain signal evolving into frequency domain, with a "waterfall" style 
% showing time slices transforming into frequency spectrum (IEEE style, all English labels)

clear; clc; close all;

% Parameters
Fs = 1000;                  % Sampling frequency (Hz)
T = 1/Fs;                   % Sampling period (s)
L = 1024;                   % Number of samples per segment
t = (0:L-1)*T;              % Time vector for one segment

% Number of time slices (for 3D effect)
N_slices = 20;              % Number of time windows

% Signal components
f1 = 50; f2 = 120; f3 = 200;   % Frequencies in Hz
x = sin(2*pi*f1*t) + 0.5*sin(2*pi*f2*t) + 0.3*sin(2*pi*f3*t);

% Create figure with IEEE style
fig = figure('Position', [100 100 900 600]);
hold on;
set(fig, 'Color', 'w');
view(45, 30);               % Nice 3D perspective
grid on;
box on;

% Colors for time and frequency domains
time_color = [0 0.4470 0.7410];   % blue
freq_color = [0.8500 0.3250 0.0980]; % red

% Generate 3D waterfall plot
for i = 1:N_slices
    % Create a time-shifted segment
    shift = (i-1)*L/2;          % Overlap for smoothness
    t_shift = t + shift*T;
    x_shift = sin(2*pi*f1*t_shift) + 0.5*sin(2*pi*f2*t_shift) + 0.3*sin(2*pi*f3*t_shift);
    
    % Time-domain curve (on the left)
    plot3(t_shift, zeros(1,L), x_shift, 'Color', time_color, ...
          'LineWidth', 1.2);
    
    % Compute FFT for this segment (magnitude spectrum)
    X = fft(x_shift);
    P2 = abs(X/L);
    P1 = P2(1:L/2+1);
    P1(2:end-1) = 2*P1(2:end-1);
    freq = (0:L/2)*Fs/L;
    
    % Frequency-domain curve (on the right, shifted in time)
    plot3(t_shift, freq, P1, 'Color', freq_color, ...
          'LineWidth', 1.2);
end

% Add reference planes for better visualization
% Time-domain plane (z=0)
surf([t(1) t(end); t(1) t(end)], [0 0; 0 0], [0 0; 0 0], ...
     'FaceColor', [0.9 0.9 0.9], 'FaceAlpha', 0.3, 'EdgeColor', 'none');
 
% Frequency-domain plane (x=max time)
surf([t(end) t(end); t(end) t(end)], [freq(1) freq(end); freq(1) freq(end)], ...
     [0 0; 0 0], 'FaceColor', [0.9 0.9 0.9], 'FaceAlpha', 0.3, 'EdgeColor', 'none');

% Labels and titles (all in English, Times New Roman)
xlabel('Time (s)', 'FontSize', 12, 'FontName', 'Times New Roman');
ylabel('Frequency (Hz)', 'FontSize', 12, 'FontName', 'Times New Roman');
zlabel('Amplitude / Magnitude', 'FontSize', 12, 'FontName', 'Times New Roman');
title('Fourier Transform: Time Domain to Frequency Domain Evolution', ...
      'FontSize', 14, 'FontName', 'Times New Roman');

% Set axes properties for IEEE style
set(gca, 'FontName', 'Times New Roman', 'FontSize', 10, 'LineWidth', 0.8);
set(gca, 'GridLineStyle', ':', 'GridAlpha', 0.3);

% Adjust view and limits
xlim([t(1) t(end)+t(end)-t(1)]);
ylim([0 300]);   % Focus on relevant frequencies
zlim([0 2.5]);
view(45, 30);

% Legend
legend({'Time Domain Signal', 'Frequency Domain Magnitude'}, ...
       'Location', 'northeast', 'FontSize', 10, 'FontName', 'Times New Roman');

hold off;